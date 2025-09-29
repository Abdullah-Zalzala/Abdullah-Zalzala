/*
/Abdullah Zalzala
csc134
9/24/2025
m3lab1
*/

// if statement example2
// standard header


// compiler directives
// (required for the program to run)
#include <iostream>
using namespace std;

// beginning of the main() method
int main() {
  
  // this program will ask a question and respond to it.
  // You should run it, and test it by typing in different values.
  // Example test values: 1, 2, 3, banana (try all of them)

  // declare the variable we need
  int choice; 
  int play;
  int chest;
  int mimic;
  int mimic2;

  // ask the question
    cout << "welcome to the haunted maze!" << endl;
     cout << "Do you choose to enter?" << endl;
    cout << "Type 1 for yes" << endl;
    cout << "Type 2 for no" << endl;
  cin >> choice;

  // using if, make a decision based on the user's choice

  if (1 == choice) {
  	cout << "You enter the maze" << endl;
  }
  else if (2 == choice) {
  	cout << "you survive" << endl;
    cout << "(Loser)" << endl;
    return 0; // exit without error
  }
  else {
  	cout << "I'm sorry, that is not a valid choice." << endl;
  }

  // finish up
  cout << "Thanks for playing!" << endl; // this runs no matter what they choose
  cout << "Do you Want To continue"<< endl; // option to continue
  cout << "type 1 for yes"<< endl;
  cout << "type 2 for no"<< endl;
  cin >> play;

  if (1 == play) {
cout << "youve entered the maze!" << endl;
  }
  if (2 == play) {
cout << "Thanks for playing!" << endl; // this runs no matter what they choose
return 0; // exit without error
}

cout << "youve found a treasure chest!" << endl;
cout << "Do you want to open it?"<< endl;
cout << "type 1 for yes"<< endl;
cout << "type 2 for no"<< endl;

cin >> chest;
if (1 == chest) {
    cout << "you found 100 gold!" << endl;
    cout << "But it was a mimic!" << endl;
    cout << "Do you want to fight it?"<< endl;
    cout << "type 1 for yes"<< endl;
    cout << "type 2 for no"<< endl;
    cin >> mimic;
    if (1 == mimic) {
        cout << "you attacked the mimic!" << endl;
        cout << "you swing and miss!" << endl;
        cout << "the mimic attacks you!" << endl;
        cout << "you lose 30 health!" << endl;
        cout << "do you contunue to fight?"<< endl;
        cout << "type 1 for yes"<< endl;
        cout << "type 2 for no"<< endl;
        cin >> mimic2;
        if (1 == mimic2) {
            cout << "you attack the mimic again!" << endl;
            cout << "you hit the mimic!" << endl;
            cout << "the mimic is defeated!" << endl;
            cout << "you win!" << endl;
        }
        if (2 == mimic2) {
            cout << "youve run away from the mimic!" << endl;
            cout << "youre too slow!" << endl;
            cout << "youve been defeated!" << endl;
            cout << "game over!" << endl;
            return 0; // end game

        }
            
            if (2 == mimic) {
                cout << "youve run away from the mimic!" << endl;
                cout << "you survived the mimic" << endl;
            }
            else {
            cout << "I'm sorry, that is not a valid choice." << endl;
            }
        } // end of mimic choice
    } // end of chest choice

if (2 == chest) {
    cout << "youve walked away from the treasure chest!" << endl;
    cout << "you survived the mimic" << endl;

}


  return 0; // exit without error
 
} // end of the main() method