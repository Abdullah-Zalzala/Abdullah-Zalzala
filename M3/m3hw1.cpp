/*
Abdullah Zalzala
10/9/2025
csc134
m3hw1
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void Question1(){
   string answer;

cout << "Hey im an new C++ programmer." << endl;
cout << "Do you like my work so far? Type yes or no." << endl;

cin >> answer;

if (answer == "yes" || answer == "Yes") {
        cout << "im glad, thank you." << endl;
}
else if (answer == "no" || answer == "No") {
        cout << "dang im sorry :( ill do better next time" << endl;
 }
else {
        cout << "I'll take that as a maybe." << endl;
}
}
void Question2(){
const double taxPercent = 0.08;

int mealMethod;
    
double tipPercent        = 0;
double mealPrice         = 0;
double taxAmount         = 0;
double tipAmount         = 0;
double totalCost         = 0;
double totalCostRounded  = 0;
double taxAmountRounded  = 0;

bool isValid;

cout << "What is the price of your meal?" << endl;
cin >> mealPrice; 
do{
cout << "Is your meal" << endl;
cout << "1. Dine-In" << endl;
cout << "2. Takeout" << endl;
cin >> mealMethod;

if(mealMethod == 1){
    tipPercent = .15;
    isValid = true;
 }
    else if(mealMethod == 2){
        tipPercent = 0.0;
        isValid = true;
    }
    else{
         cout << "i see youd like to cook for yourself, go to walmart" << endl;
         isValid = false;
     }
}while(isValid == false);
    
tipAmount = mealPrice * tipPercent;
taxAmount = mealPrice * taxPercent;
totalCost = mealPrice + taxAmount + tipAmount;

 cout << setprecision(2) << fixed;
cout << "Meal(1)   $" << mealPrice << endl;
cout << endl;
cout << "Subtotal: $" << mealPrice << endl;
cout << "Tax 1:    $" << taxAmount << endl;
cout << "Tip:      $" << tipAmount << endl;
cout << endl;
cout << "Total:    $" << totalCost << endl;

}

void Question3(){
int choice;
char playAgain = 'y';

cout << "=== Welcome to the dungoen Adventure! ===" << endl;

while (playAgain == 'y' || playAgain == 'Y') {
    cout << "You and your party randomly stumble across a dungoen in the middle of the forest." << endl;
    cout << "What do you do?" << endl;
    cout << "1. Go inside?" << endl;
    cout << "2. Walk Past" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 2) {
        cout << "Your party chose to walk past the dungoen" << endl;
        cout << "Unfortunately, run into a bear and all get mauled." << endl;
        cout << "GAME OVER." << endl;
      
    }
    else if (choice == 1) {
cout << "You walk inside the dungoen" << endl;
cout << "your party follows close behind." << endl;
cout << "you stumble into a room with a sleeping dragon." << endl;
cout << "What do you do?" << endl;
cout << "1. Sneak past" << endl;
cout << "2. fight" << endl;
cout << "Enter choice: ";
cin >> choice;
cout << endl;
if (choice == 2) {
cout << "your party chooses to attempt to fight." << endl;
cout << "the dragon uses a single breath of fire and burns you all to a crisp." << endl;
cout << "DEFEAT." << endl;
}
 else if (choice == 1) {
cout << "your party all successfully sneaks past the dragon and you notice a door behind it" << endl;
cout << "you enter into a treasure room with gold and glory" << endl;
cout << "VICTORY!" << endl;
 }
else {
 cout << "That wasn't a valid option" << endl;
 }
}
else {
 cout << "That wasn't a valid option" << endl;
 }

cout << "Would you like to play again? (y/n): ";
 cin >> playAgain;
}

 cout << "Thanks for playing dungoen Adventure!" << endl;
}

void Question4(){
int adden1, adden2, sum, userInput;
char tryAgainChar;
bool tryAgainBool = true;
bool isValid = true;

while(tryAgainBool == true){

adden1 = (rand() % 9999) + 1;
adden2 = (rand() % 9999) + 1;
cout << "What is the summ of " <<adden1 << " + " << adden2 << "?" << endl;
sum = adden1 + adden2;
cin >> userInput;
if (userInput == sum){
cout << "Correct!" << endl;
 } 
 else{
cout << "Sorry your answer is wrong. The correct answer is " << sum << "." << endl;
}
do{
cout << "Would you like to try again? (y/n)" << endl;
cin >> tryAgainChar;
if(tryAgainChar == 'Y' || tryAgainChar == 'y'){
 tryAgainBool = true;
}
else if(tryAgainChar == 'N' || tryAgainChar == 'n'){
tryAgainBool = false;
cout << "Goodbye." << endl;
}
else{
cout << "Invalid Input please enter y/n." << endl;
isValid = false;
}
}while(isValid == false);
        
}
}

int main(){
srand(time(0));

int questionChoice;
 bool runAgain = true;
bool isValid  = false;
char runAgainChar;

do{
do{
cout << "1. Question 1: Chat Bot" << endl;
cout << "2. Question 2: Receipt Calculator" << endl;
cout << "3. Question 3: Choose Your Own Adventure" << endl;
cout << "4. Question 4: Math Practice" << endl;
runAgain = false;
cin >> questionChoice;
switch(questionChoice){
case 1:
Question1();
isValid = true;
break;
case 2:
Question2();
isValid = true;
break;
case 3:
Question3();
isValid = true;
break;
case 4:
Question4();
isValid = true;
break;
default:
cout << "Invalid Input. Please enter a number 1-4." << endl;
isValid = false;
}
}while(isValid == false);
cout << "Would you like to run another program? (y/n)" << endl;
do{
cin >> runAgainChar;
if(runAgainChar == 'Y' || runAgainChar == 'y'){
runAgain = true;
}
else if(runAgainChar == 'N' || runAgainChar == 'n'){
runAgain = false;
cout << "Goodbye." << endl;
}
else{
cout << "Invalid Input please enter y/n." << endl;
isValid = false;
}
}while(isValid == false);
}while(runAgain == true);
return 0;
}