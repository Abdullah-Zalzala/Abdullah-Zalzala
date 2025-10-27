#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

// ====== Card / Deck ======
struct Card {
    int rank; // 1..13 (Ace=1, J=11, Q=12, K=13)
    int suit; // 0..3 (♠ ♥ ♦ ♣)
};

static const char* SUITS[] = {"\xE2\x99\xA0", "\xE2\x99\xA5", "\xE2\x99\xA6", "\xE2\x99\xA3"}; // ♠ ♥ ♦ ♣

string rankToStr(int r) {
    if (r == 1) return "A";
    if (r >= 2 && r <= 10) return to_string(r);
    if (r == 11) return "J";
    if (r == 12) return "Q";
    return "K";
}
string cardToStr(const Card& c) { return rankToStr(c.rank) + SUITS[c.suit]; }

int baseValue(int rank) {
    if (rank >= 2 && rank <= 10) return rank;
    if (rank >= 11) return 10;
    return 11; // Ace defaults to 11, adjusted later
}

struct Shoe {
    vector<Card> cards;
    mt19937 rng;
    int numDecks;

    Shoe(int decks=6): numDecks(decks) {
        random_device rd; rng.seed(rd());
        reset(numDecks);
    }

    void reset(int decks) {
        numDecks = decks;
        cards.clear();
        cards.reserve(decks * 52);
        for (int d = 0; d < decks; ++d) {
            for (int s = 0; s < 4; ++s) {
                for (int r = 1; r <= 13; ++r) {
                    cards.push_back({r, s});
                }
            }
        }
        shuffle(cards.begin(), cards.end(), rng);
    }

    Card draw() {
        if (cards.empty()) reset(numDecks);
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};

// ====== Scoring ======
int bestHandTotal(const vector<Card>& hand, int target) {
    int total = 0, aces = 0;
    for (auto& c : hand) {
        if (c.rank == 1) { aces++; total += 11; }
        else total += baseValue(c.rank);
    }
    while (total > target && aces > 0) { total -= 10; --aces; }
    return total;
}
bool isBust(const vector<Card>& hand, int target) { return bestHandTotal(hand, target) > target; }
bool isTwoCard(const vector<Card>& h) { return h.size() == 2; }

bool isPerfect18_A7(const vector<Card>& hand, int target) {
    if (target != 18 || !isTwoCard(hand)) return false;
    bool hasAce = (hand[0].rank == 1) || (hand[1].rank == 1);
    bool hasSeven = (hand[0].rank == 7) || (hand[1].rank == 7);
    return hasAce && hasSeven;
}
bool isBlackjack21(const vector<Card>& hand, int target) {
    if (target != 21 || !isTwoCard(hand)) return false;
    bool hasAce = (hand[0].rank == 1) || (hand[1].rank == 1);
    bool hasTenVal = (baseValue(hand[0].rank) == 10) || (baseValue(hand[1].rank) == 10);
    return hasAce && hasTenVal && bestHandTotal(hand, 21) == 21;
}
bool canSplit(const vector<Card>& hand) {
    if (hand.size() != 2) return false;
    return baseValue(hand[0].rank) == baseValue(hand[1].rank);
}

// ====== Modes / Rules ======
enum class Mode { EIGHTEEN=1, BLACKJACK21=2, THIRTY=3 };

struct Rules {
    int target;
    int dealerStandMin;           // dealer stands when total >= this
    bool playerWinsTieAtTarget;   // only for EIGHTEEN: player wins 18-18
    bool specialPerfect18;        // A+7 two-card pays 2.5x
    bool blackjackMode;           // natural 21 3:2 payout
    bool splitAcesOneCardOnly;    // in 21 mode only
};

Rules rulesFor(Mode m) {
    switch (m) {
        case Mode::EIGHTEEN:
            return Rules{18, 16, true,  true,  false, false};
        case Mode::BLACKJACK21:
            return Rules{21, 17, false, false, true,  true}; // stand on all 17s
        case Mode::THIRTY:
        default:
            return Rules{30, 26, false, false, false, false};
    }
}

// ====== IO Helpers ======
void printHand(const string& who, const vector<Card>& hand, int target, bool hideFirst=false) {
    cout << who << ": ";
    if (hideFirst && !hand.empty()) {
        cout << "[??] ";
        for (size_t i = 1; i < hand.size(); ++i) cout << cardToStr(hand[i]) << " ";
        cout << "\n";
    } else {
        for (auto& c : hand) cout << cardToStr(c) << " ";
        cout << "(total: " << bestHandTotal(hand, target) << ")\n";
    }
}

long long getBet(long long chips) {
    while (true) {
        cout << "You have " << chips << " chips. Enter bet (1-" << chips << "): ";
        long long b;
        if (!(cin >> b)) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n"; continue;
        }
        if (b < 1 || b > chips) { cout << "Bet out of range.\n"; continue; }
        return b;
    }
}

int askIntInRange(const string& prompt, int lo, int hi, int defVal) {
    cout << prompt << " [" << lo << "-" << hi << "] (default " << defVal << "): ";
    string s; getline(cin >> ws, s);
    if (s.empty()) return defVal;
    try {
        int v = stoi(s);
        if (v < lo || v > hi) throw runtime_error("oob");
        return v;
    } catch (...) {
        cout << "Using default " << defVal << ".\n";
        return defVal;
    }
}

Mode chooseMode() {
    cout << "Choose mode:\n";
    cout << "  1) Eighteen (Rule of 18)\n";
    cout << "  2) Blackjack (21)\n";
    cout << "  3) Thirty (30)\n";
    cout << "Enter 1, 2, or 3: ";
    int x;
    while (true) {
        if (cin >> x && (x>=1 && x<=3)) break;
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter 1, 2, or 3: ";
    }
    return static_cast<Mode>(x);
}

// ====== Hand wrapper to track per-hand state ======
struct PlayerHand {
    vector<Card> cards;
    long long bet = 0;
    bool doubled = false;
    bool splitFromAces = false;   // in blackjack, split aces rule
    bool stood = false;
    bool finished = false;
};

int compareHands(const vector<Card>& player, const vector<Card>& dealer, const Rules& R) {
    bool pBust = isBust(player, R.target);
    bool dBust = isBust(dealer, R.target);
    if (pBust && dBust) return 0; // both bust -> push (rare)
    if (pBust) return -1;
    if (dBust) return 1;

    int p = bestHandTotal(player, R.target);
    int d = bestHandTotal(dealer, R.target);

    if (R.playerWinsTieAtTarget && p == R.target && d == R.target) return 1;
    if (p > d) return 1;
    if (p < d) return -1;
    return 0; // push
}

long long settleOne(long long chips, const PlayerHand& H, const vector<Card>& dealer, const Rules& R, bool earlyBJHandled) {
    long long bet = H.bet * (H.doubled ? 2 : 1);

    // Natural blackjack is paid early (before actions) and not here
    // Eighteen perfect A+7 is paid here if it wins.
    int cmp = compareHands(H.cards, dealer, R);
    if (cmp == 1) {
        if (R.specialPerfect18 && isPerfect18_A7(H.cards, R.target)) {
            cout << "Perfect 18 (A+7)! Pays 2.5x on base bet.\n";
            // For doubled hands, keep it simple: pay based on current bet amount.
            chips += (long long)(2.5 * bet);
        } else {
            cout << "Win (+1x).\n";
            chips += 2 * bet;
        }
    } else if (cmp == 0) {
        cout << "Push. Bet returned.\n";
        chips += bet;
    } else {
        cout << "Lose.\n";
    }
    return chips;
}

// ====== Main ======
int main() {
   // ios::sync_with_stdio(false);
   // cin.tie(nullptr);

    cout << "=== Cards — Eighteen / Blackjack / Thirty ===\n";
    cout << "Modes:\n";
    cout << " - Eighteen: dealer stands 16–18, A+7 pays 2.5x, player wins 18-18 ties.\n";
    cout << " - Blackjack (21): dealer stands on 17 (incl. soft), natural blackjack pays 3:2,\n";
    cout << "   split once; split Aces get one card only, then stand; ties push.\n";
    cout << " - Thirty: dealer stands on 26–30; ties push.\n\n";

    // Choose shoe size
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear any leftover newline
    int decks = askIntInRange("How many decks in the shoe?", 1, 8, 6);
    Shoe shoe(decks);

    long long chips = 200;
    string again = "y";

    while (again == "y" || again == "Y") {
        if (chips <= 0) { cout << "You're out of chips. Game over.\n"; break; }

        Mode mode = chooseMode();
        Rules R = rulesFor(mode);

        long long baseBet = getBet(chips);
        chips -= baseBet;

        // Initial deal
        vector<Card> dealer;
        vector<PlayerHand> hands(1);
        hands[0].bet = baseBet;
        hands[0].cards.push_back(shoe.draw());
        dealer.push_back(shoe.draw());
        hands[0].cards.push_back(shoe.draw());
        dealer.push_back(shoe.draw());

        cout << "\n--- Deal ---\n";
        printHand("Dealer", dealer, R.target, true);
        printHand("Player (Hand 1)", hands[0].cards, R.target, false);

        // Early naturals in Blackjack only
        bool earlyBJResolved = false;
        if (R.blackjackMode) {
            bool pBJ = isBlackjack21(hands[0].cards, R.target);
            bool dBJ = isBlackjack21(dealer, R.target);
            if (pBJ || dBJ) {
                cout << "\n--- Reveal for Blackjack ---\n";
                printHand("Dealer", dealer, R.target, false);
                if (pBJ && dBJ) {
                    cout << "Both have blackjack. Push.\n";
                    chips += baseBet;
                    earlyBJResolved = true;
                } else if (pBJ) {
                    cout << "Blackjack! Pays 3:2.\n";
                    chips += (long long)(2.5 * baseBet);
                    earlyBJResolved = true;
                } else {
                    cout << "Dealer blackjack. You lose.\n";
                    earlyBJResolved = true;
                }
            }
        }

        // Player actions (including split/double) unless already resolved
        if (!earlyBJResolved) {
            // Optional single split per original hand
            for (size_t h = 0; h < hands.size(); ++h) {
                auto& H = hands[h];
                bool hasSplitOnce = false;

                // Offer split if allowed and we have chips to match bet
                if (canSplit(H.cards) && chips >= H.bet) {
                    cout << "\nHand " << (h+1) << " can (P)split, (H)it, (S)tand, (D)ouble: ";
                } else {
                    cout << "\nHand " << (h+1) << " choose (H)it, (S)tand, (D)ouble";
                    if (canSplit(H.cards)) cout << " [need more chips to split]";
                    cout << ": ";
                }

                // Hand loop
                bool firstAction = true;
                while (!H.finished) {
                    string s; cin >> s;
                    char c = s.empty() ? ' ' : (char)tolower(s[0]);

                    bool splitAllowed = (!hasSplitOnce) && canSplit(H.cards) && chips >= H.bet;

                    // Validate options prompt dynamically
                    auto printPrompt = [&]() {
                        cout << "(H)it, (S)tand";
                        if (firstAction) cout << ", (D)ouble";
                        if (splitAllowed && firstAction) cout << ", (P)split";
                        cout << "? ";
                    };

                    if (c == 'p' && firstAction && splitAllowed) {
                        // perform split into two hands
                        cout << "Splitting hand " << (h+1) << "...\n";
                        hasSplitOnce = true;

                        Card c0 = H.cards[0];
                        Card c1 = H.cards[1];
                        H.cards = {c0, shoe.draw()};
                        PlayerHand newH;
                        newH.bet = H.bet;
                        newH.cards = {c1, shoe.draw()};
                        // Split Aces rule (blackjack only)
                        if (R.blackjackMode && c0.rank == 1 && c1.rank == 1) {
                            H.splitFromAces = true;
                            newH.splitFromAces = true;
                            H.stood = true; H.finished = true;
                            newH.stood = true; newH.finished = true;
                            cout << "Split Aces: each hand receives one card and stands.\n";
                        }
                        // Deduct matched bet
                        chips -= newH.bet;
                        // Insert new hand after current
                        hands.insert(hands.begin() + h + 1, newH);

                        // Show both hands
                        printHand("Player (After Split) - Hand " + to_string(h+1), H.cards, R.target, false);
                        printHand("Player (After Split) - Hand " + to_string(h+2), hands[h+1].cards, R.target, false);

                        // If split aces stood, break out to next hand
                        if (H.finished) break;

                        // Still player on current hand; re-prompt first action
                        cout << "Hand " << (h+1) << " ";
                        printPrompt();
                        firstAction = true; // still first action (post-split)
                        continue;
                    }
                    else if (c == 'd' && firstAction) {
                        // Double-down: take exactly one card, double bet, auto-stand
                        if (chips < H.bet) {
                            cout << "Not enough chips to double. ";
                            printPrompt();
                            continue;
                        }
                        H.doubled = true;
                        chips -= H.bet;
                        H.bet *= 2; // track as doubled bet for simplicity
                        H.cards.push_back(shoe.draw());
                        printHand("Player (Double) - Hand " + to_string(h+1), H.cards, R.target, false);
                        if (isBust(H.cards, R.target)) cout << "You busted.\n";
                        H.stood = true; H.finished = true;
                        break;
                    }
                    else if (c == 'h') {
                        // Cannot hit on split Aces in blackjack (but those are already auto-finished)
                        H.cards.push_back(shoe.draw());
                        printHand("Player (Hit) - Hand " + to_string(h+1), H.cards, R.target, false);
                        if (isBust(H.cards, R.target)) { cout << "You busted.\n"; H.finished = true; }
                        // auto-stand on exact target
                        else if (bestHandTotal(H.cards, R.target) == R.target) { cout << "Reached " << R.target << ".\n"; H.stood = true; H.finished = true; }
                    }
                    else if (c == 's') {
                        H.stood = true; H.finished = true;
                    }
                    else {
                        cout << "Invalid choice. ";
                        printPrompt();
                        continue;
                    }

                    firstAction = false;
                    if (!H.finished) {
                        cout << "Hand " << (h+1) << " ";
                        cout << "(H)it or (S)tand? ";
                    }
                }
            }
        }

        // Dealer turn (if at least one hand not resolved by dealer BJ early)
        cout << "\n--- Dealer's Turn ---\n";
        printHand("Dealer", dealer, R.target, false);

        // If early BJ resolved, we already paid/collected and skip dealer hitting.
        if (!earlyBJResolved) {
            // Dealer hits until stand min
            while (bestHandTotal(dealer, R.target) < R.dealerStandMin) {
                cout << "Dealer hits.\n";
                dealer.push_back(shoe.draw());
                printHand("Dealer", dealer, R.target, false);
                if (isBust(dealer, R.target)) { cout << "Dealer busted.\n"; break; }
            }
            if (!isBust(dealer, R.target) && bestHandTotal(dealer, R.target) >= R.dealerStandMin) {
                cout << "Dealer stands.\n";
            }
        }

        // Results (per hand)
        cout << "\n--- Results ---\n";
        printHand("Dealer", dealer, R.target, false);
        for (size_t i = 0; i < hands.size(); ++i) {
            cout << "Hand " << (i+1) << ": ";
            printHand("Player", hands[i].cards, R.target, false);

            if (earlyBJResolved) {
                // Already handled; no more hands should exist in BJ early-resolved scenario,
                // but in case of future changes, treat as push here.
                cout << "Round already settled due to blackjack. (No change)\n";
            } else {
                chips = settleOne(chips, hands[i], dealer, R, false);
            }
        }

        cout << "Chips: " << chips << "\n\n";

        // Reshuffle if shoe is low
        if ((int)shoe.cards.size() < max(20, decks*10)) {
            cout << "[Reshuffling shoe]\n";
            shoe.reset(decks);
        }

        cout << "Play another round? (y/n): ";
        cin >> again;
        cout << "\n";
    }

    cout << "Thanks for playing!\n";
    return 0;
}
