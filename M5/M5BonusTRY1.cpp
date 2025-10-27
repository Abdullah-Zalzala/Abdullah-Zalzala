/*
Abdullah Zalzala
10/27/2025
m5bonus.cpp
18 blackjack variant game implementation
used chat gpt
*/



#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

using namespace std;

struct Card {
    int rank; // 1..13 (Ace=1, Jack=11, Queen=12, King=13)
    int suit; // 0..3 (S, H, D, C)
};

static const char* SUITS[] = {"S", "H", "D", "C"}; // ASCII suits for portability

string rankToStr(int r) {
    if (r == 1)  return "A";
    if (r <= 10) return to_string(r);
    if (r == 11) return "J";
    if (r == 12) return "Q";
    return "K";
}

string cardToStr(const Card& c) {
    return rankToStr(c.rank) + string(SUITS[c.suit]);
}

struct Deck {
    vector<Card> cards;
    mt19937 rng;
    Deck() {
        random_device rd;
        rng.seed(rd()); // portable seeding
        reset();
    }
    void reset() {
        cards.clear();
        cards.reserve(52);
        for (int s = 0; s < 4; ++s)
            for (int r = 1; r <= 13; ++r)
                cards.push_back({r, s});
        shuffle(cards.begin(), cards.end(), rng);
    }
    Card draw() {
        if (cards.empty()) reset();
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};

int pipValue(int rank) {
    if (rank >= 2 && rank <= 10) return rank;
    if (rank >= 11 && rank <= 13) return 10; // J Q K
    return 11; // Ace as 11 initially (we'll adjust)
}

int bestHandTotal(const vector<Card>& hand) {
    int total = 0;
    int aces = 0;
    for (const auto& c : hand) {
        if (c.rank == 1) { ++aces; total += 11; }
        else total += pipValue(c.rank);
    }
    while (total > 18 && aces > 0) {
        total -= 10; // make an Ace count as 1 instead of 11
        --aces;
    }
    return total;
}

bool isBust(const vector<Card>& hand) {
    return bestHandTotal(hand) > 18;
}

bool isPerfect18_AcePlus7(const vector<Card>& hand) {
    if (hand.size() != 2) return false;
    bool hasAce = (hand[0].rank == 1) || (hand[1].rank == 1);
    bool hasSeven = (hand[0].rank == 7) || (hand[1].rank == 7);
    return hasAce && hasSeven; // Ace(11) + 7 = 18
}

void printHand(const string& who, const vector<Card>& hand, bool hideFirst=false) {
    cout << who << ": ";
    if (hideFirst && !hand.empty()) {
        cout << "[??] ";
        for (size_t i = 1; i < hand.size(); ++i) cout << cardToStr(hand[i]) << " ";
        cout << "\n";
    } else {
        for (const auto& c : hand) cout << cardToStr(c) << " ";
        cout << "(total: " << bestHandTotal(hand) << ")\n";
    }
}

int compareHands(const vector<Card>& player, const vector<Card>& dealer) {
    // 1 = player win, 0 = push, -1 = dealer win
    bool pBust = isBust(player), dBust = isBust(dealer);
    int p = bestHandTotal(player), d = bestHandTotal(dealer);

    if (pBust && dBust) return 0; // both bust -> push
    if (pBust) return -1;
    if (dBust) return 1;

    // Player wins ties at exactly 18
    if (p == 18 && d == 18) return 1;

    if (p > d) return 1;
    if (p < d) return -1;
    return 0; // other ties push
}

long long settleBet(long long chips, long long bet,
                    const vector<Card>& player, const vector<Card>& dealer) {
    int result = compareHands(player, dealer);
    bool playerPerfect18 = (!isBust(player) && bestHandTotal(player) == 18 && isPerfect18_AcePlus7(player));

    if (result == 1) {
        if (playerPerfect18) {
            // bet already subtracted; add back 2.5 * bet (return + winnings)
            chips += static_cast<long long>(2.5 * bet);
            cout << "You WIN! (Perfect 18 pays 2.5x)\n";
        } else {
            chips += 2 * bet; // return bet + 1x winnings
            cout << "You WIN! (+1x)\n";
        }
    } else if (result == 0) {
        chips += bet;
        cout << "Push. Your bet is returned.\n";
    } else {
        cout << "Dealer wins.\n";
    }
    return chips;
}

long long getBet(long long chips) {
    while (true) {
        cout << "You have " << chips << " chips. Enter bet (1–" << chips << "): ";
        long long b;
        if (!(cin >> b)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        if (b < 1 || b > chips) {
            cout << "Bet out of range.\n";
            continue;
        }
        return b;
    }
}

char getAction() {
    while (true) {
        cout << "(H)it or (S)tand? ";
        string s; cin >> s;
        if (!s.empty()) {
            char c = static_cast<char>(tolower(static_cast<unsigned char>(s[0])));
            if (c == 'h' || c == 's') return c;
        }
        cout << "Please type H or S.\n";
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); // ???

    cout << "=== Eighteen (Rule of 18) ===\n";
    cout << "Objective: get as close to 18 as possible without busting.\n";
    cout << "- Face cards = 10, Aces = 1 or 11.\n";
    cout << "- Dealer hits on <16, stands on 16–18.\n";
    cout << "- Two-card Perfect 18 (Ace + 7) pays 2.5x.\n";
    cout << "- Player wins tie at exactly 18. Other ties push. Both bust = push.\n\n";

    Deck deck;
    long long chips = 100;
    string again = "y";

    while (again == "y" || again == "Y") {
        if (chips <= 0) {
            cout << "You're out of chips. Game over.\n";
            break;
        }

        long long bet = getBet(chips);
        chips -= bet;

        vector<Card> player, dealer;
        player.push_back(deck.draw());
        dealer.push_back(deck.draw());
        player.push_back(deck.draw());
        dealer.push_back(deck.draw());

        cout << "\n--- Deal ---\n";
        printHand("Dealer", dealer, /*hideFirst=*/true);
        printHand("Player", player);

        bool playerBusted = false;
        while (true) {
            if (bestHandTotal(player) == 18) {
                cout << "You have 18!\n";
                break;
            }
            char act = getAction();
            if (act == 'h') {
                player.push_back(deck.draw());
                printHand("Player", player);
                if (isBust(player)) {
                    cout << "You busted.\n";
                    playerBusted = true;
                    break;
                }
            } else {
                break; // stand
            }
        }

        cout << "\n--- Dealer's Turn ---\n";
        printHand("Dealer", dealer, /*hideFirst=*/false);
        if (!playerBusted) {
            while (bestHandTotal(dealer) < 16) {
                cout << "Dealer hits.\n";
                dealer.push_back(deck.draw());
                printHand("Dealer", dealer, false);
                if (isBust(dealer)) {
                    cout << "Dealer busted.\n";
                    break;
                }
            }
            if (!isBust(dealer) && bestHandTotal(dealer) >= 16 && bestHandTotal(dealer) <= 18) {
                cout << "Dealer stands.\n";
            }
        }

        cout << "\n--- Result ---\n";
        printHand("Dealer", dealer);
        printHand("Player", player);

        chips = settleBet(chips, bet, player, dealer);
        cout << "Chips: " << chips << "\n\n";

        cout << "Play another round? (y/n): ";
        cin >> again;
        cout << "\n";

        if (static_cast<int>(deck.cards.size()) < 15) deck.reset();
    }

    cout << "Thanks for playing Eighteen!\n";
    return 0;
}
