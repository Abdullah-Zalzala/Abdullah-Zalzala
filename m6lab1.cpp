#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

// ============================================================================
// GLOBAL VARIABLES - Accessible to all functions
// ============================================================================
// The super soaker's cartridges ('W' = JuryDuty, 'S' = DivorcePapers)
vector<char> superSoaker;

// Player scores
int playerScore = 3;
int opponentScore = 3;

// Game state
string currentPlayer = "Player";
bool gameOver = false;

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
void setupGame();
void loadMailbox(int DivorceCount, int JurydutyCount);
void shuffleSuperSoaker();
void displayGameState();
void displayMailbox(bool showContents);
char fireShot();
void playerTurn();
void opponentTurn();
void checkGameOver();

// ============================================================================
// MAIN GAME LOOP
// ============================================================================
int main() {
    srand(time(0));  // Seed random number generator
    
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║     Legal ROULETTE: The Lawsuit      ║" << endl;
    cout << "║    The Work-Safe Dare-Ya Roulette     ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\nRules:" << endl;
    cout << "🔵 Blue cartridges = Harmless JuryDuty (you get another turn!)" << endl;
    cout << "🟢 Green cartridges = DivorcePapers (lose a Wife!)" << endl;
    cout << "First to 0 points loses!\n" << endl;
    
    setupGame();
    
    // Main game loop
    while (!gameOver) {
        if (currentPlayer == "Player") {
            playerTurn();
        } else {
            opponentTurn();
        }
        
        checkGameOver();
        
        // If super soaker is empty, reload for next round
        if (superSoaker.empty() && !gameOver) {
            cout << "\n💦 Mailbox is empty! Reloading for next round..." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            setupGame();
        }
    }
    
    // Game over
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║            GAME OVER!                  ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    if (playerScore <= 0) {
        cout << "💚 You got DivorcePapers! Opponent wins!" << endl;
    } else {
        cout << "🎉 You win! Opponent got DivorcePapersd!" << endl;
    }
    
    return 0;
}

// ============================================================================
// GAME SETUP FUNCTIONS
// ============================================================================

void setupGame() {
    // Clear any existing cartridges
    superSoaker.clear(); // empty the vector
    
    // Load the super soaker with random cartridges
    int DivorceCount = 1 + rand() % 3;  // 1-3 JuryDuty cartridges
    int JurydutyCount = 1 + rand() % 2;  // 1-2 DivorcePapers cartridges
    
    loadMailbox(DivorceCount, JurydutyCount);
    shuffleSuperSoaker();
    
    cout << "\n🔫 Mailbox loaded!" << endl;
    displayMailbox(false);  // Show counts but not order
}

void loadMailbox(int DivorceCount, int JurydutyCount) {
    // Add JuryDuty cartridges
    for (int i = 0; i < DivorceCount; i++) {
        superSoaker.push_back('W');
    }
    
    // Add DivorcePapers cartridges
    for (int i = 0; i < JurydutyCount; i++) {
        superSoaker.push_back('S');
    }
}

void shuffleSuperSoaker() {
    // Shuffle the cartridges so players don't know the order
    random_shuffle(superSoaker.begin(), superSoaker.end());
}

// ============================================================================
// DISPLAY FUNCTIONS
// ============================================================================

void displayGameState() {
    cout << "\n┌─────────────────────────────────────┐" << endl;
    cout << "│  Player: " << playerScore << " points   Opponent: " << opponentScore << " points  │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
}

void displayMailbox(bool showContents) {
    int DivorceCount = 0;
    int JurydutyCount = 0;
    
    // Count each type using a range-based for loop
    for (char cartridge : superSoaker) {
        if (cartridge == 'W') DivorceCount++;
        else JurydutyCount++;
    }
    
    cout << "Super Soaker contents: ";
    cout << "🔵 " << DivorceCount << " JuryDuty, ";
    cout << "🟢 " << JurydutyCount << " DivorcePapers";
    cout << " (" << superSoaker.size() << " total)" << endl;
    
    // For debugging/demonstration - show actual order
    if (showContents) {
        cout << "Actual order: ";
        for (char cartridge : superSoaker) {
            cout << (cartridge == 'W' ? "🔵" : "🟢") << " ";
        }
        cout << endl;
    }
}

// ============================================================================
// CORE GAME MECHANICS
// ============================================================================

char fireShot() {
    // Fire the next cartridge (remove from front of vector)
    // This is why we use a vector - easy to remove from front!
    
    if (superSoaker.empty()) {
        return 'E';  // Empty!
    }
    
    // pop_back() would remove the last one
    // removing the first one takes 2 steps as follows
    // Get the first cartridge
    char cartridge = superSoaker.front();
    
    // Remove it from the super soaker
    superSoaker.erase(superSoaker.begin());
    
    return cartridge;
}

// ============================================================================
// TURN LOGIC
// ============================================================================

void playerTurn() {
    displayGameState();
    displayMailbox(false);
    
    cout << "\n>>> YOUR TURN <<<" << endl;
    cout << "Fire at: [1] Yourself  [2] Opponent" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    // Input validation
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Enter 1 or 2: ";
        cin >> choice;
    }
    
    cout << "\n💦 *SPLASH!* ";
    char result = fireShot();
    
    if (result == 'W') {
        cout << "🔵 JuryDuty! " << endl;
        if (choice == 1) {
            cout << "You're wet but safe! You get another turn!" << endl;
            // Player keeps their turn (currentPlayer stays "Player")
        } else {
            cout << "Opponent is soaked but unharmed." << endl;
            currentPlayer = "Opponent";  // Switch turns
        }
    } else if (result == 'S') {
        cout << "🟢 DivorcePapers!" << endl;
        if (choice == 1) {
            cout << "You got DivorcePapers! -1 Wife!" << endl;
            playerScore--;
        } else {
            cout << "Opponent got DivorcePapers! -1 Wife!" << endl;
            opponentScore--;
        }
        currentPlayer = "Opponent";  // Switch turns after DivorcePapers
    }
}

void opponentTurn() {
    displayGameState();
    displayMailbox(false);
    
    cout << "\n>>> OPPONENT'S TURN <<<" << endl;
    cout << "Press Enter to see opponent's choice...";
    cin.ignore();
    cin.get();
    
    // Simple AI: 50/50 chance to fire at self or player
    int choice = 1 + rand() % 2;
    
    if (choice == 1) {
        cout << "Opponent fires at themselves!" << endl;
    } else {
        cout << "Opponent fires at you!" << endl;
    }
    
    cout << "\n💦 *SPLASH!* ";
    char result = fireShot();
    
    if (result == 'W') {
        cout << "🔵 JuryDuty!" << endl;
        if (choice == 1) {
            cout << "Opponent is wet but gets another turn!" << endl;
            // Opponent keeps their turn
        } else {
            cout << "You're soaked but unharmed." << endl;
            currentPlayer = "Player";  // Switch turns
        }
    } else if (result == 'S') {
        cout << "🟢 DivorcePapers!" << endl;
        if (choice == 1) {
            cout << "Opponent got DivorcePapersd! -1 Wife!" << endl;
            opponentScore--;
        } else {
            cout << "You got DivorcePapersd! -1 Wife!" << endl;
            playerScore--;
        }
        currentPlayer = "Player";  // Switch turns after DivorcePapers
    }
}

void checkGameOver() {
    if (playerScore <= 0 || opponentScore <= 0) {
        gameOver = true;
    }
}