/*
Abdullah Zalzala
10/6/2025
csc134
m4lab1
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare our variables
    string character; 
    int defense;
    int strength;
    int intelligence;
    int cool;
    int health;
    int maxHealth;
    int magic;
    int CharacterType;  // Declare the variable to store the user's choice

    cout << "Welcome to the dungeon!" << endl;
    cout << "Choose your Class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Spy" << endl;
    cout << "4. Healer" << endl;
    cout << "5. Tank" << endl;
    
    // Get user input for the character type
    cin >> CharacterType;

    // Initialize stats based on character type
    if (CharacterType == 1) {
        character = "Warrior";
        defense = 50;
        strength = 80;
        intelligence = 30;
        cool = 75;
        health = 100;
        maxHealth = 100;
        magic = 10;
    }
    else if (CharacterType == 2) {
        character = "Mage";
        defense = 20;
        strength = 20;
        intelligence = 100;
        cool = 80;
        health = 100;
        maxHealth = 100;
        magic = 100;
    }
    else if (CharacterType == 3) {
        character = "Spy";
        defense = 30;
        strength = 40;
        intelligence = 80;
        cool = 30;
        health = 60;
        maxHealth = 60;
        magic = 50;
    }
    else if (CharacterType == 4) {
        character = "Healer";
        defense = 60;
        strength = 20;
        intelligence = 60;
        cool = 75;
        health = 150;
        maxHealth = 150;
        magic = 80;
    }
    else if (CharacterType == 5) {
        character = "Tank";
        defense = 100;
        strength = 60;
        intelligence = 40;
        cool = 100;
        health = 200;
        maxHealth = 200;
        magic = 0;
    }
    else {
        cout << "Invalid choice. Please choose a number between 1 and 5." << endl;
        return 1;  // Exit the program if invalid input
    }

    // Output the chosen character and their stats
    cout << "You chose " << character << endl;
    cout << "________Character Stats________" << endl;
    cout << "Defense: " << defense << endl;
    cout << "Strength: " << strength << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Cool: " << cool << endl;
    cout << "Health: " << health << endl;
    cout << "Max Health: " << maxHealth << endl;
    cout << "Magic: " << magic << endl;







    
    return 0;
}