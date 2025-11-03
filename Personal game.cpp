/*
Abdullah Zalzala
10/6/2025
csc134
m4lab1
*/

#include <iostream>
#include <string>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <limits>  // numeric_limits
#include <iomanip> // setw, left, right
using namespace std;

// ---------------- Function Prototypes ----------------
void PickClass(string &character, int &defense, int &strength, int &intelligence,
               int &cool, int &health, int &maxHealth, int &magic);
void Rest(int &health, int maxHealth);
bool HideSucceeds(int cool);
bool AttackHits(int chance);
void WolfBattle(int &health, int &defense, int &strength, int &intelligence,
                int &cool, int &maxHealth, int &magic, int &damageBonus);
void LevelUp(int &defense, int &strength, int &intelligence, 
             int &cool, int &maxHealth, int &magic, int &health);

// New helpers for ring room + inventory + checklist demos
void EnterRingRoomAndInventory(int &damageBonus);
void RecoverLoop(); // Exercise 1
void LevelTable(int baseDef, int baseStr, int baseInt, int baseCool, int baseMaxHP, int baseMag); // Exercise 2

// ------------------------------------------------------

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // seed random

    string character; 
    int defense;
    int strength;
    int intelligence;
    int cool;
    int health;
    int maxHealth;
    int magic;
    int damageBonus = 0; // NEW: bonus damage from items (ring = +20)

    // Pick class (recursively re-asks if invalid)
    PickClass(character, defense, strength, intelligence, cool, health, maxHealth, magic);

    // Display chosen character and stats
    cout << "\nYou chose " << character << endl;
    cout << "________Character Stats________" << endl;
    cout << "Defense: " << defense << endl;
    cout << "Strength: " << strength << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Cool: " << cool << endl;
    cout << "Health: " << health << endl;
    cout << "Max Health: " << maxHealth << endl;
    cout << "Magic: " << magic << endl;

    cout << "\n________Story Time________" << endl;
    cout << "You take a deep breath as you and your party enter the dark dungeon." << endl;
    cout << "An eerie mist swirls around you..." << endl;
    cout << "All of a sudden, your entire party falls to the floor unconscious!" << endl;
    cout << "You wake up after 10 minutes." << endl;

    cout << "\nWhile you were unconscious, your body began to recover..." << endl;
    Rest(health, maxHealth);
    cout << "\nYou open your eyes feeling completely restored." << endl;
    cout << "Your current health: " << health << "/" << maxHealth << endl;
    cout << "You stand up, ready to face what lies ahead in the dungeon..." << endl;

    cout << "You turn to see your party members still unconscious." << endl;
    cout << "There is a sign on the wall that reads: 'If you want to save your friends, you must find the antidote at the end of the mist.'" << endl;

    cout << "\nDo you wish to proceed deeper into the dungeon? (y/n): ";
    string choice;
    cin >> choice;

    if (choice == "y" || choice == "Y") {
        cout << "You bravely venture deeper into the dungeon, determined to find the antidote and save your friends." << endl;
    } else {
        cout << "You decide to leave your party behind." << endl;
        return 0;
    }

    // Hide or confront decision
    cout << "\nAll of a sudden, as you move forward into the tunnel, you hear a faint set of footsteps echoing through the mist." << endl;
    cout << "Do you want to try to hide or confront whoever is coming? (y = hide / n = confront): ";
    string decision;
    cin >> decision;

    if (decision == "y" || decision == "Y") {
        cout << "You quickly find a hiding spot behind a large rock, holding your breath..." << endl;

        bool hidden = HideSucceeds(cool);

        if (hidden) {
            cout << "Your cool composure keeps you perfectly still. The figure passes by without noticing you." << endl;
            cout << "You remain hidden and avoid the confrontation.\n";
            // ➜ Ring room after sneaking past
            EnterRingRoomAndInventory(damageBonus);
        } else {
            cout << "You shift slightly... A stone scrapes. The figure whips around and spots you!" << endl;
            cout << "You've been discovered — it's a feral wolf!\n";
            WolfBattle(health, defense, strength, intelligence, cool, maxHealth, magic, damageBonus);
            // If you survive and/or defeat the wolf, you'll be taken to ring room inside WolfBattle().
        }
    } 
    else if (decision == "n" || decision == "N") {
        cout << "You step forward boldly, calling out to whoever is approaching." << endl;
        cout << "You see a wolf emerging from the shadows — eyes glowing red!" << endl;
        cout << "Prepare for battle!" << endl;
        WolfBattle(health, defense, strength, intelligence, cool, maxHealth, magic, damageBonus);
    } 
    else {
        cout << "You hesitate, unsure what to do... the footsteps grow closer." << endl;
        cout << "The wolf notices you anyway!\n";
        WolfBattle(health, defense, strength, intelligence, cool, maxHealth, magic, damageBonus);
    }

    return 0;
}

// ---------------- Helper Functions ----------------

// Rest: heals by +10 until full using recursion (no loops)
void Rest(int &health, int maxHealth) {
    if (health >= maxHealth) {
        cout << "Your health is fully restored (" << health << "/" << maxHealth << ")." << endl;
    } 
    else if (health + 10 <= maxHealth) {
        health = health + 10;
        cout << "Recovering... +10 health (" << health << "/" << maxHealth << ")." << endl;
        Rest(health, maxHealth);
    } 
    else if (health + 10 > maxHealth) {
        health = maxHealth;
        cout << "Recovering... health capped at max (" << health << "/" << maxHealth << ")." << endl;
        Rest(health, maxHealth);
    }
}

// Hide success based on cool %
bool HideSucceeds(int cool) {
    if (cool < 0) cool = 0;
    else if (cool > 100) cool = 100;

    if (cool <= 0) return false;
    else if (cool >= 100) return true;

    int roll = (rand() % 100) + 1;
    if (roll <= cool) return true;
    else return false;
}

// Attack hit chance
bool AttackHits(int chance) {
    if (chance >= 100) return true;
    else if (chance <= 0) return false;

    int roll = (rand() % 100) + 1;
    if (roll <= chance) return true;
    else return false;
}

// Wolf battle — one round, chance-based; on victory ➜ LevelUp then Ring room
void WolfBattle(int &health, int &defense, int &strength, int &intelligence,
                int &cool, int &maxHealth, int &magic, int &damageBonus) {

    int wolfHealth = 50;
    int wolfAttack = 20;
    int wolfHitChance = 80;
    int playerHitChance = 70;

    cout << "\nThe Wolf snarls and lunges at you!\n";

    // Wolf attacks first
    bool wolfHits = AttackHits(wolfHitChance);
    if (wolfHits) {
        int damage = wolfAttack - (defense / 10);
        if (damage < 0) damage = 0;
        health = health - damage;
        cout << "The Wolf bites you! You take " << damage << " damage.\n";
    } 
    else {
        cout << "The Wolf snaps at you but misses!\n";
    }

    if (health <= 0) {
        cout << "You collapse to the ground... defeated by the Wolf.\n";
        return;
    }

    // Player’s turn (uses bonus damage from gear)
    bool playerHits = AttackHits(playerHitChance);
    if (playerHits) {
        int playerDamage = (strength / 2) + damageBonus; // <-- bonus applied
        wolfHealth = wolfHealth - playerDamage;
        cout << "You strike the Wolf for " << playerDamage << " damage!\n";
    } 
    else {
        cout << "You swing your weapon, but the Wolf dodges!\n";
    }

    if (wolfHealth <= 0) {
        cout << "\nThe Wolf falls to the ground, defeated!\n";
        LevelUp(defense, strength, intelligence, cool, maxHealth, magic, health);
        // ➜ Then ring room
        EnterRingRoomAndInventory(damageBonus);
    } 
    else {
        cout << "The Wolf growls — it’s still standing with " 
             << wolfHealth << " HP remaining!\n";
        cout << "Your current health: " << health << endl;
    }
}

// Level Up: +5 to all stats
void LevelUp(int &defense, int &strength, int &intelligence, 
             int &cool, int &maxHealth, int &magic, int &health) {

    cout << "\n========== LEVEL UP! ==========\n";
    cout << "Victory surges through your veins — you feel stronger!\n";
    cout << "Each of your core stats increases by +5!\n\n";

    int oldDefense = defense;
    int oldStrength = strength;
    int oldIntelligence = intelligence;
    int oldCool = cool;
    int oldMaxHealth = maxHealth;
    int oldMagic = magic;

    defense += 5;
    strength += 5;
    intelligence += 5;
    cool += 5;
    maxHealth += 5;
    magic += 5;

    health = maxHealth;

    cout << "Defense: " << oldDefense << " → " << defense << endl;
    cout << "Strength: " << oldStrength << " → " << strength << endl;
    cout << "Intelligence: " << oldIntelligence << " → " << intelligence << endl;
    cout << "Cool: " << oldCool << " → " << cool << endl;
    cout << "Max Health: " << oldMaxHealth << " → " << maxHealth << endl;
    cout << "Magic: " << oldMagic << " → " << magic << endl;
    cout << "================================\n";
    cout << "Your wounds heal as your power surges. Health restored to " 
         << health << "/" << maxHealth << "!\n";
    cout << "================================\n";
}

// ================== RING ROOM + INVENTORY + CHECKLIST DEMOS ==================
void EnterRingRoomAndInventory(int &damageBonus) {
    cout << "\nYou enter a quiet stone chamber. At its center lies a small pedestal.\n";
    cout << "Upon it rests a gleaming band etched with a wolf’s fang.\n";
    cout << "You obtained: Wolf-Fang Ring! (Damage +20)\n";
    damageBonus += 20;

    // ---------------- Inventory (Exercise 3 requirements) ----------------
    // TODO: Create your equipment array with 5 items
    string equipment[5] = {
        "Iron Sword",
        "Leather Armor",
        "Health Potion",
        "Wolf-Fang Ring (+20 DMG)", // placed here
        "Rope"
    };

    // TODO: Display all items using a for loop
    cout << "\n=== YOUR INVENTORY ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << equipment[i] << endl; // numbered 1–5
    }
    cout << "======================" << endl << endl;

    // TODO: Get search term from user
    cout << "Enter item to search for: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer before getline
    string searchTerm;
    getline(cin, searchTerm);

    // TODO: Search for the item using a loop
    bool found = false;
    int position = -1;
    for (int i = 0; i < 5; i++) {
        if (equipment[i] == searchTerm) {
            found = true;
            position = i;
            break; // Stop searching once found
        }
    }

    // TODO: Display search results
    if (found) {
        cout << "Found \"" << searchTerm << "\" in slot " 
             << (position + 1) << "!" << endl; // position shown as 1–5
    } else {
        cout << "\"" << searchTerm << "\" not found in inventory." << endl;
    }

    // ---------------- TESTING CHECKLIST DEMOS ----------------
    cout << "\n\nTESTING CHECKLIST:\n";
    cout << "Exercise 1 (Health loop demo):\n";
    RecoverLoop();

    cout << "\nExercise 2 (10-level stat growth table):\n";
    // For demo, assume level-up pattern is +5 per level for all stats.
    // Use a reasonable base so the table is readable.
    LevelTable(50, 80, 30, 30, 100, 10);

    cout << "\nExercise 3 (Inventory list + search) done above.\n";
    cout << "Common mistakes avoided: array indices, off-by-one, infinite loops, display numbering 1–5.\n\n";
}

// -------------------- DEMO EXERCISES --------------------

void RecoverLoop() {
    // Exercise 1:
    // [x] Health starts at 30
    // [x] Health increases by 10 each loop
    // [x] Loop stops at exactly 100
    // [x] "Fully recovered!" message displays
    // [x] No infinite loop!

    int health = 30;
    cout << "Start health: " << health << endl;

    // Using a for loop to clearly hit exactly 100
    for (; health < 100; ) {
        health += 10;
        cout << "Recovering... +" << 10 << " -> " << health << endl;
        if (health >= 100) {
            health = 100;
            break; // ensure exact stop at 100
        }
    }

    if (health == 100) {
        cout << "Fully recovered!" << endl;
    }
}

void LevelTable(int baseDef, int baseStr, int baseInt, int baseCool, int baseMaxHP, int baseMag) {


    cout << left << setw(6) << "Lvl"
         << setw(9)  << "Defense"
         << setw(9)  << "Str"
         << setw(9)  << "Int"
         << setw(9)  << "Cool"
         << setw(10) << "MaxHP"
         << setw(9)  << "Magic" << endl;

    cout << string(60, '-') << endl;

    // Level 1..10, +5 per level
    for (int lvl = 1; lvl <= 10; lvl++) {
        int add = (lvl - 1) * 5;
        cout << left << setw(6) << lvl
             << setw(9)  << (baseDef + add)
             << setw(9)  << (baseStr + add)
             << setw(9)  << (baseInt + add)
             << setw(9)  << (baseCool + add)
             << setw(10) << (baseMaxHP + add)
             << setw(9)  << (baseMag + add) << endl;
    }

    // Total growth from level 1 to 10 is 9 * 5 = +45 per stat
    cout << "\nTotal growth per stat over 10 levels: +45" << endl;
}

// ================== CLASS SELECTION ==================
void PickClass(string &character, int &defense, int &strength, int &intelligence,
               int &cool, int &health, int &maxHealth, int &magic) {

    int CharacterType;

    cout << "Welcome to the dungeon!" << endl;
    cout << "Choose your Class:" << endl;
    cout << "1. Warrior\n2. Mage\n3. Spy\n4. Healer\n5. Tank\n> ";
    cin >> CharacterType;

    if (CharacterType == 1) {
        character = "Warrior";
        defense = 50; strength = 80; intelligence = 30;
        cool = 30; health = 60; maxHealth = 100; magic = 10;
    }
    else if (CharacterType == 2) {
        character = "Mage";
        defense = 20; strength = 20; intelligence = 100;
        cool = 60; health = 50; maxHealth = 100; magic = 100;
    }
    else if (CharacterType == 3) {
        character = "Spy";
        defense = 30; strength = 40; intelligence = 80;
        cool = 90; health = 20; maxHealth = 60; magic = 50;
    }
    else if (CharacterType == 4) {
        character = "Healer";
        defense = 60; strength = 20; intelligence = 60;
        cool = 50; health = 100; maxHealth = 150; magic = 80;
    }
    else if (CharacterType == 5) {
        character = "Tank";
        defense = 100; strength = 60; intelligence = 40;
        cool = 10; health = 150; maxHealth = 200; magic = 0;
    }
    else {
        cout << "Invalid choice. Please enter a number between 1 and 5.\n\n";
        cin.clear();
        cin.ignore(1000, '\n');
        PickClass(character, defense, strength, intelligence, cool, health, maxHealth, magic);
    }
}