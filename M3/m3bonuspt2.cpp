#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

const int NUM_DICE = 5;
const int NUM_CATEGORIES = 13;

// Rolls one die
int rollDie() {
    return rand() % 6 + 1;
}

// Roll selected dice
void rollDice(vector<int>& dice, vector<bool>& keep) {
    for (int i = 0; i < NUM_DICE; i++) {
        if (!keep[i]) {
            dice[i] = rollDie();
        }
    }
}

// Display current dice
void showDice(const vector<int>& dice) {
    cout << "Dice: ";
    for (int i = 0; i < NUM_DICE; i++) {
        cout << "[" << i+1 << ":" << dice[i] << "] ";
    }
    cout << endl;
}

// Count frequency of each face (1–6)
vector<int> getCounts(const vector<int>& dice) {
    vector<int> counts(7, 0); // index 1–6
    for (int val : dice) {
        counts[val]++;
    }
    return counts;
}

// Calculate score for a category
int scoreCategory(int category, const vector<int>& dice) {
    vector<int> counts = getCounts(dice);
    int total = 0;

    switch (category) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            return counts[category] * category; // upper section

        case 7: // Three of a kind
            for (int i = 1; i <= 6; i++) {
                if (counts[i] >= 3) {
                    for (int d : dice) total += d;
                    return total;
                }
            }
            return 0;

        case 8: // Four of a kind
            for (int i = 1; i <= 6; i++) {
                if (counts[i] >= 4) {
                    for (int d : dice) total += d;
                    return total;
                }
            }
            return 0;

        case 9: // Full house (3 + 2)
            if ((find(counts.begin(), counts.end(), 3) != counts.end()) &&
                (find(counts.begin(), counts.end(), 2) != counts.end())) {
                return 25;
            }
            return 0;

        case 10: // Small straight (4 in sequence)
        {
            vector<int> uniq;
            for (int i = 1; i <= 6; i++) if (counts[i] > 0) uniq.push_back(i);
            string seq;
            for (int x : uniq) seq += to_string(x);
            if (seq.find("1234") != string::npos ||
                seq.find("2345") != string::npos ||
                seq.find("3456") != string::npos) return 30;
            return 0;
        }

        case 11: // Large straight (5 in sequence)
        {
            vector<int> uniq;
            for (int i = 1; i <= 6; i++) if (counts[i] > 0) uniq.push_back(i);
            string seq;
            for (int x : uniq) seq += to_string(x);
            if (seq == "12345" || seq == "23456") return 40;
            return 0;
        }

        case 12: // Yahtzee (all 5 same)
            for (int i = 1; i <= 6; i++) if (counts[i] == 5) return 50;
            return 0;

        case 13: // Chance (sum of all dice)
            for (int d : dice) total += d;
            return total;
    }
    return 0;
}

// Ask player which dice to keep
void chooseKeeps(vector<bool>& keep) {
    cout << "Enter dice numbers to keep (e.g., 1 3 5), or 0 for none: ";
    int k;
    while (cin >> k) {
        if (k == 0) break;
        if (k >= 1 && k <= NUM_DICE) keep[k-1] = true;
        if (cin.peek() == '\n') break;
    }
}

// Main game loop
int main() {
    srand(time(0));

    vector<int> scores(NUM_CATEGORIES+1, -1); // -1 = not used
    int totalScore = 0;

    cout << "=== Welcome to Yahtzee! ===\n";

    for (int turn = 1; turn <= NUM_CATEGORIES; turn++) {
        cout << "\n--- Turn " << turn << " ---\n";

        vector<int> dice(NUM_DICE);
        vector<bool> keep(NUM_DICE, false);

        // Up to 3 rolls
        for (int roll = 1; roll <= 3; roll++) {
            rollDice(dice, keep);
            cout << "Roll " << roll << ": ";
            showDice(dice);

            if (roll < 3) {
                keep.assign(NUM_DICE, false); // reset
                cout << "Do you want to keep any dice? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    chooseKeeps(keep);
                }
            }
        }

        // Choose scoring category
        cout << "\nAvailable categories:\n";
        cout << "1-Ones  2-Twos  3-Threes  4-Fours  5-Fives  6-Sixes\n";
        cout << "7-3Kind  8-4Kind  9-FullHouse  10-SmallStraight\n";
        cout << "11-LargeStraight  12-Yahtzee  13-Chance\n";

        int cat;
        do {
            cout << "Choose category (1-13): ";
            cin >> cat;
        } while (cat < 1 || cat > 13 || scores[cat] != -1);

        int score = scoreCategory(cat, dice);
        scores[cat] = score;
        totalScore += score;

        cout << "Scored " << score << " points in category " << cat << "!\n";
        cout << "Total so far: " << totalScore << endl;
    }

    cout << "\n=== Final Score: " << totalScore << " ===\n";
    return 0;
}