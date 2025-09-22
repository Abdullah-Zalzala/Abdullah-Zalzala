/*
Abdullah Zalzala
csc134
9/22/2025
M3T2
*/
#include <iostream>
#include <cstdlib> // for rand
#include <ctime>

using namespace std;

//declare helper functions
int roll();

int main() {
cout << "Welcome To The Better Dice Game" << endl;

int roll1;
int roll2;
int point;

srand (time(0));
//roll the dice
roll1 = roll();
roll2 = roll();
int sum = roll1 + roll2;
cout << "Roll:"<< sum << endl;

    cout << "Dice 1 Rolled a "<< roll1 << endl;
    cout << "Dice 2 Rolled a "<< roll2 << endl;
    cout << "you rolled a " << sum << endl;
if ( (sum == 7) || (sum == 11) ) {
    cout << "lucky seven -- you win!" << endl;
}

else if ( (sum ==2) || (sum == 3) || (sum == 12) ) {
    cout << "2,3,12 -- Sorry, you lose." << endl;
}
else {

    point = sum;
    cout << "rolled a point." << endl;
    cout << "your point is:"<< point << endl;
    cout << "You Lose :(" << endl;
}
return 0;
}


int roll () {
// define the function
int my_roll =( rand() % 6) +1; // 1-6
return my_roll;
}