/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Abdullah Zalzala
11/04/2025
*/



#include <iostream>
using namespace std;



void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_secret_basement();
void choice_run_away();

int main() {
  cout << "M5LAB1" << endl;
  main_menu();
  cout << "Thanks for playing!" << endl;
  return 0;
}

void main_menu() {
  int choice;
  while (true) {
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "You're in front of a spooky old house..." << endl;
    cout << "Do you:" << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. Sneak around back" << endl;
    cout << "3. Forget it, and go home" << endl;
    cout << "4. Quit" << endl;
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
      choice_front_door();
    } else if (choice == 2) {
      choice_back_door();
    } else if (choice == 3) {
      choice_go_home();
    } else if (choice == 4) {
      cout << "Ok, quitting game." << endl;
      break;
    } else {
      cout << "That's not a valid choice, please try again." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
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
    choice_back_door();
  } else if (choice == 2) {
    cout << endl;
    cout << "You knock on the door. Suddenly, it creaks open by itself..." << endl;
    choice_secret_basement();
  } else if (choice == 3) {
    choice_go_home();
  } else {
    cout << "Invalid choice, returning to main menu." << endl;
  }
}

void choice_back_door() {
  cout << endl;
  cout << "You sneak around the back. The grass is overgrown and you trip on a root." << endl;
  cout << "You see a small basement door half-open." << endl;
  cout << "Do you:" << endl;
  cout << "1. Enter the basement" << endl;
  cout << "2. Run away while you still can" << endl;

  int choice;
  cout << "Choose: ";
  cin >> choice;

  if (choice == 1) {
    choice_secret_basement();
  } else if (choice == 2) {
    choice_run_away();
  } else {
    cout << "Invalid choice, returning to main menu." << endl;
  }
}

void choice_go_home() {
  cout << endl;
  cout << "You decide it’s not worth it and start walking home." << endl;
  cout << "The sky darkens, but you feel strangely relieved." << endl;
  cout << "You made it home safe — maybe the mystery can wait another day." << endl;
}

void choice_secret_basement() {
  cout << endl;
  cout << "You open the basement door and step inside." << endl;
  cout << "Cobwebs cover everything, and a single candle lights the room." << endl;
  cout << "Suddenly, you hear whispering: 'You shouldn’t have come here...'" << endl;
  cout << "Do you:" << endl;
  cout << "1. Investigate the whisper" << endl;
  cout << "2. Run for your life!" << endl;

  int choice;
  cout << "Choose: ";
  cin >> choice;

  if (choice == 1) {
    cout << endl;
    cout << "You follow the voice and find an old diary on a table." << endl;
    cout << "It tells the story of the house’s last owner." << endl;
    cout << "Congratulations, you discovered the secret of the haunted house!" << endl;
  } else if (choice == 2) {
    choice_run_away();
  } else {
    cout << "Invalid choice, returning to main menu." << endl;
  }
}

void choice_run_away() {
  cout << endl;
  cout << "You sprint away as fast as you can!" << endl;
  cout << "You don’t stop until you reach the road." << endl;
  cout << "Your heart is racing, but you’re safe." << endl;
  cout << "Maybe next time you’ll be braver." << endl;
}
