/*
Abdullah Zalzala
10/5/2025
m5lab1inclass.cpp
*/

#include <iostream>
using namespace std;


int  getPlayerChoice(int maxChoice); // let player choose options
void showChoices(string choice1, string choice2, string choice3);  // display the player choice menus

void game_start();
const int MAX = 3; // max possible choices per node


// main()
int main() {

    game_start();

    return 0;
}


int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= maxChoice) {
            return choice; // same number they enter
        }

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}

void showChoices(string choice1, string choice2, string choice3) {

    cout << "---- MAKE YOUR CHOICE ----" << endl;
    int num = 1;
    cout << num << ". " << choice1 << endl;
    num++;

    if (choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }

    if (choice3 != "") {
        cout << num << ". " << choice3 << endl;
        num++;
    }

}



void game_start() {

    
   int choice;

   cout << R"(You're standing in front of the spooky old house again. 
    It's almost Thanksgiving but their Halloween decorations 
    are still up.

    You think you see a light in the back...?
    )";
 
    showChoices("Go check the front door.",
                "Walk around back and check the garden",
                "Forget it and go home.");



    choice = getPlayerChoice(MAX);
    if (choice == 1) {
        cout << "Going in the front." << endl;
   
    }
    if (choice == 2) {
        cout << "Headed around back..." << endl;

        

    }
    if (choice == 3) {
        cout << "Forget it, let's get pizza." << endl;
    }
}

void choice_front_door() {
  cout << endl;
  cout << "You try the front door..." << endl;
  cout << "It's locked tight, but you hear faint music inside." << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Knock loudly" << endl;
  cout << "3. Give up and go home" << endl;

  int choice;
  cout << "Choose: ";
  cin >> choice;

  if (choice == 1) {
cout << "You Choose To check around back"  << endl;



}
    } 
    else if (choice == 2) {
    cout << "You Choose To Knock Loudly"  << endl;



    }

    else if (choice == 3) {
    cout << "You Choose To Go Home"  << endl;
return 0;
}