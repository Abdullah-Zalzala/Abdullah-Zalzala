/*
Abdullah Zalzala
11/17/2025
m6lab2
*/

#include <iostream>
#include <string>
using namespace std;

// Directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Rooms
enum Room {
    ENTRANCE_HALL = 0,
    BATHROOM = 1,
    ATTIC = 2,
    HALLWAY = 3,
    BASEMENT = 4,
    INVESTIGATE = 5,
    CLOSET = 6,
    NUM_ROOMS = 7
};

int main() {

    // Room names
    string roomNames[NUM_ROOMS] = {
        "Entrance Hall",
        "Bathroom",
        "Attic",
        "Hallway",
        "Basement",
        "Toilet Investigation",
        "Closet"
    };

    // Room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with old porcelain tiles and a strangely wooden toilet.",
        "A spacious attic filled with old furniture and cobwebs.",
        "An old and dirty hallway with two doors.",
        "A dark, damp basement. The door looks locked.",
        "You found a key inside the toilet tank!",
        "A small, dusty closet filled with broken shelves."
    };

    // Adjacency matrix
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Initialize everything to -1
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }

    // Entrance Hall
    connections[ENTRANCE_HALL][NORTH] = BATHROOM;
    connections[ENTRANCE_HALL][EAST]  = ATTIC;
    connections[ENTRANCE_HALL][WEST]  = HALLWAY;

    // Bathroom
    connections[BATHROOM][SOUTH] = ENTRANCE_HALL;
    connections[BATHROOM][EAST]  = INVESTIGATE;

    // Investigate toilet
    connections[INVESTIGATE][WEST] = BATHROOM;

    // Hallway
    connections[HALLWAY][EAST]  = CLOSET;
    connections[HALLWAY][WEST]  = ENTRANCE_HALL;
    connections[HALLWAY][SOUTH] = BASEMENT;  // BASEMENT (locked until key found)

    // Closet
    connections[CLOSET][WEST] = HALLWAY;

    // Attic
    connections[ATTIC][EAST] = ENTRANCE_HALL;

    // Basement
    connections[BASEMENT][NORTH] = ATTIC;

    // Game state
    int currentRoom = ENTRANCE_HALL;
    bool running = true;

    // KEY FLAG
    bool hasKey = false;

    while (running) {
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;

        // Picking up key automatically
        if (currentRoom == INVESTIGATE && !hasKey) {
            hasKey = true;
            cout << "\n[TRUE] You found a key! You can now open the basement door.\n";
        }

        // Show exits
        cout << "Exits: ";
        bool hasExit = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (connections[currentRoom][d] != -1) {

                // Special case: basement locked
                if (connections[currentRoom][d] == BASEMENT && !hasKey) {
                    cout << "(locked south) ";
                } else {
                    cout << DIRECTION_NAMES[d] << " ";
                }

                hasExit = true;
            }
        }
        if (!hasExit) cout << "none";
        cout << endl;

        // Command input
        string cmd;
        cout << "\nWhat would you like to do? ";
        cin >> cmd;

        int chosenDir = -1;

        if (cmd == "north" || cmd == "n") chosenDir = NORTH;
        else if (cmd == "east" || cmd == "e") chosenDir = EAST;
        else if (cmd == "south" || cmd == "s") chosenDir = SOUTH;
        else if (cmd == "west" || cmd == "w") chosenDir = WEST;
        else if (cmd == "quit" || cmd == "q") {
            running = false;
            break;
        } else {
            cout << "Unknown command.\n";
            continue;
        }

        // Check if movement is possible
        int nextRoom = connections[currentRoom][chosenDir];

        // If no exit in that direction
        if (nextRoom == -1) {
            cout << "You can't go that way.\n";
            continue;
        }

        // If trying to enter basement without key
        if (nextRoom == BASEMENT && !hasKey) {
            cout << "\nThe basement door is locked. You need a key.\n";
            continue;
        }

        // Otherwise move
        currentRoom = nextRoom;
    }

    cout << "\nThanks for playing!\n";
    return 0;
}