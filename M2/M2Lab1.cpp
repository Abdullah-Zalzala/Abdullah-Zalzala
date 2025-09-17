/*
csc 134
m2lab - case study with crates
abdullah
9/8/2025
*/

#include <iostream>
using namespace std;

int main () 
{
//Ask the user to input the crate’s length.
//Ask the user to input the crate’s width.
//Ask the user to input the crate’s height.
//Calculate the crate’s volume.
//Calculate the cost of building the crate.
//Calculate the customer’s charge for the crate.
//Calculate the profit made from the crate.
//Display the crate’s volume.
//Display the cost of building the crate.
//Display the customer’s charge for the crate.
//Display the profit made from the crate.
    double length, width, height; // size of crate
    double volume;
    double cost_to_make, charge_to_customer; // pricing
    double profit;

    const double COST_PER_CUBIC_FOOT = 0.23; // relates to cost
    const double CHARGE_PER_CUBIC_FOOT = 0.5; // relates to charge
// get the crate info
cout << "welcome to the crate program. " << endl;
cout << "crate length: ";
cin >> length;
cout << "Crate Width: ";
cin >> width;
cout << "Crate height: ";
cin >> height;

// calculate the cost and prices
volume = length * width * height;
cost_to_make        =volume * COST_PER_CUBIC_FOOT;
charge_to_customer  =volume * CHARGE_PER_CUBIC_FOOT;
profit = charge_to_customer - cost_to_make;
//display the results
cout << endl;
cout << "your crate is " << volume << " cubic feet." << endl;
cout << "customer price: $" << charge_to_customer << endl;
cout << "cost to build : $" << cost_to_make << endl;
cout << "profit        : $" << profit << endl;

return 0; // no errors
}