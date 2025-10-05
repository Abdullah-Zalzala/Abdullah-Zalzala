/*
Abdullah Zalzala
10/1/2025
csc134
m3bonus
*/


#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;



int rolldie() {

 
	return rand() % 6 + 1;
}

void rollDice(int dice[], int numDice) {
	cout << "rolling " << numDice << " dice...\n";
	for (int i = 0; i < numDice; i++) {
		dice[i] = rolldie();
		cout << "die " << i+1 << "; " << dice[i] << endl;
	}
}

int main() {
       cout << "Welcome to the 5 dice demon" << endl;
       cout << "Rules : You Must Get Above 20 to win" << endl;
       cout << "If You lose You Die" << endl;
       cout << "Good Luck" << endl;
       cout << "____________________________________" << endl;
    
	srand(time(0));
	const int NUM_DICE = 5;
	int dice[NUM_DICE] = {0};
	rollDice(dice, NUM_DICE);

    int dice_sum = dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; 
    cout << "SUM IS: " << dice_sum << endl;

    if dice_sum <20 
 cout << "you Died"
 return 0
}

	return 0;
}

        