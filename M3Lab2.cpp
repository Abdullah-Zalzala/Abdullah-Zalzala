/*
abdullah Zalzala
9/29/2025
M3Lab2
*/

#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;    

void letter_grader();
void combat();
void teacher();
void hunter ();
int main () {

cout << "are you a teacher or a hunter?" << endl;
string role;
cin >> role;

if (role == "teacher") {
    letter_grader();
}
if (role == "hunter") {
    combat();
}
return 0;

}


void letter_grader() {

double num_grade;
string letter_grade;


    cout << "enter a number grade between 0 and 100"<< endl;
cin >> num_grade;



const double A1_Grade = 100;
const double A_Grade = 90;
const double B_Grade = 80;
const double C_Grade = 70;
const double D_Grade = 60;

if (num_grade >= A1_Grade) {
    letter_grade = "A++";
}
else
if (num_grade >= A_Grade) {
    letter_grade = "A";
}
else if (num_grade >= B_Grade) {
    letter_grade = "B";
}
else if (num_grade >= C_Grade) {
    letter_grade = "C";
}
else if (num_grade >= D_Grade) {
    letter_grade = "D";
}
else {
    letter_grade = "F";
}cout << " a number grade of " << num_grade << " is a(n) " << letter_grade << endl;

}


void combat() {





    int attack_roll, attack_bonus, enemy_warrior;
    cout << "you are fighting a barbarian!" << endl;
    cout << "enter your roll: " << endl;
    cin >> attack_roll;
    cout << "enter your attack bonus: " << endl;
    cin >> attack_bonus;
    cout << " enter the enemy barbarians armor class: " << endl;
    cin >> enemy_warrior;

    // roll to hit
    if (attack_roll + attack_bonus >= enemy_warrior) {
        cout << "hit!" << endl;
    
    }
    else {
        cout << "miss!" << endl;

    }
cout << "again? (y/n)" << endl;
string again;
cin >> again;
if (again == "y") { 

combat ();
}








}

