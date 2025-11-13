/*
Abdullah Zalzala
11/13/2025
m5hw1.cpp

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ---------------------------------------------
// QUESTION 1: Average Rainfall
// ---------------------------------------------
void question1() {
    string m1, m2, m3;
    double r1, r2, r3;

    cout << "Enter month: ";
    cin >> m1;
    cout << "Enter rainfall for " << m1 << ": ";
    cin >> r1;

    cout << "Enter month: ";
    cin >> m2;
    cout << "Enter rainfall for " << m2 << ": ";
    cin >> r2;

    cout << "Enter month: ";
    cin >> m3;
    cout << "Enter rainfall for " << m3 << ": ";
    cin >> r3;

    double avg = (r1 + r2 + r3) / 3.0;

    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << m1 << ", " << m2 << ", and " << m3
         << " is " << avg << " inches." << endl << endl;
}



// ---------------------------------------------
// QUESTION 2: Volume of a Hyperrectangle
// ---------------------------------------------
void question2() {
    double width, length, height;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter height: ";
    cin >> height;

    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Error: No dimension can be zero or less." << endl << endl;
        return;
    }

    double volume = width * length * height;

    cout << "The volume of the block is: " << volume << endl << endl;
}



// ---------------------------------------------
// QUESTION 3: Roman Numeral Converter
// ---------------------------------------------
void question3() {
    int num;
    cout << "Enter a number (1 - 10): ";
    cin >> num;

    if (num < 1 || num > 10) {
        cout << "Error: Number must be 1 through 10." << endl << endl;
        return;
    }

    cout << "The Roman numeral version of " << num << " is ";

    switch (num) {
        case 1:  cout << "I"; break;
        case 2:  cout << "II"; break;
        case 3:  cout << "III"; break;
        case 4:  cout << "IV"; break;
        case 5:  cout << "V"; break;
        case 6:  cout << "VI"; break;
        case 7:  cout << "VII"; break;
        case 8:  cout << "VIII"; break;
        case 9:  cout << "IX"; break;
        case 10: cout << "X"; break;
    }

    cout << "." << endl << endl;
}


