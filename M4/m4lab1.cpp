/*
Abdullah Zalzala
csc134
m4lab1
*/
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    cout << "=== Exercise 1: Health Recovery ===" << endl;
    int health = 30;
    cout << "Start health: " << health << endl;
    while (health < 100) {
        health += 10;
        if (health > 100) {
            health = 100;
        }
        cout << "Recovering... +10 => " << health << endl;
    }
    if (health == 100) {
        cout << "Fully recovered!" << endl;
    }
    cout << endl;

    cout << "=== Exercise 2: Level Growth (Listed) ===" << endl;
    int baseDefense = 50;
    int baseStrength = 80;
    int baseIntelligence = 30;
    int baseCool = 30;
    int baseMaxHealth = 100;
    int baseMagic = 10;
    cout << "Level | Defense | Str | Int | Cool | MaxHP | Magic" << endl;
    cout << "---------------------------------------------------" << endl;
    for (int lvl = 1; lvl <= 10; ++lvl) {
        int add = (lvl - 1) * 5;
        cout << "  " << lvl
             << "    | "
             << (baseDefense + add) << "      | "
             << (baseStrength + add) << "  | "
             << (baseIntelligence + add) << "  | "
             << (baseCool + add) << "   | "
             << (baseMaxHealth + add) << "    | "
             << (baseMagic + add) << endl;
    }
    cout << endl;
    cout << "Total growth per stat from Level 1 to 10: +" << (9 * 5) << endl;
    cout << endl;

    cout << "=== Exercise 3: Inventory & Search ===" << endl;
    string equipment[5] = {
        "Iron Sword",
        "Leather Armor",
        "Health Potion",
        "Magic Ring",
        "Rope"
    };
    cout << "=== YOUR INVENTORY ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << equipment[i] << endl;
    }
    cout << "======================" << endl;
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter item to search for: ";
    string searchTerm;
    getline(cin, searchTerm);
    bool found = false;
    int position = -1;
    for (int i = 0; i < 5; i++) {
        if (equipment[i] == searchTerm) {
            found = true;
            position = i;
            break;
        }
    }
    if (found) {
        cout << "Found \"" << searchTerm << "\" in slot " << (position + 1) << "!" << endl;
    } else {
        cout << "\"" << searchTerm << "\" not found in inventory." << endl;
    }
    cout << endl;
    cout << "--- End of Checklist Demo ---" << endl;
    return 0;
}
// i know that i had a whole game sorted before but im moving it into a seperate area so i can focus on the checklist only