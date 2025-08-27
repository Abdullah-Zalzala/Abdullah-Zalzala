/*
scs 134
m1lab
Abdullah
8/27/2025
Purpose: The "Life" (Replace Noun) Sales Program
*/

// Magic words
#include <iostream>
using namespace std;

int main () {
    // start program
    // declare all variables ("nouns")
    string item = "dice"; // replace with your item 
    int quantity = 10;
double price = 2.50; // replace with your price

// give our sales pitch
    cout << "Welcome to the " << item << " Store!" << endl;
    cout << "Each " << item << " is $" << price << endl;
    cout << "We have " << quantity << " in total." << endl;
// do the processing
  double total_cost = quantity * price;
// print the results
cout << "If you buy all " << quantity << " " << item << "(s), it will cost you $" << total_cost << endl;
cout << "Thank you for coming to the " << item << " Store!" << endl;
    // end program
    return 0;
}