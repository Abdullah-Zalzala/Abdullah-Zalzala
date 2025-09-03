/*
Csc 134, m2t1
Abdullah
9/3/25
Revission of "Sales" Program from M1, now with user input
*/

#include <iostream>
using namespace std;

int main() {
 // declare variables ("the truth")
string item = "watermelon";
double cost_per = 5.00;
int quantity = 12;
// variables foruser input
int amount_purchased;
double total_cost;

  // Greet The User
  cout << "Welcome to the " << item << " store." << endl;
  // Ask for information
cout << "each of the " << item << "Cost $" << cost_per << endl;
cout << "we have" << quantity << "for sale." << endl;
cout << endl;
cout << "how many would you like to buy?" << endl;
// cin: put the information from the keyboard into a variable
cin >> amount_purchased;

// do some processing
// I say single equal as "gets" 
total_cost = amount_purchased * cost_per;
// TODO
// output the answer
   cout <<"you are buying " << amount_purchased << " " << item << endl;
   cout <<"the total is: $" << total_cost << endl;
   cout << "thank you for shopping with us." << endl;
  return 0;
}