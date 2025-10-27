/*
Abdullah Zalzala    
10/27/2025
M4HW1.cpp   
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number from 1 to 12: ";
    cin >> num;
    while (num < 1 || num > 12) {
        cout << "Invalid input. Please enter a number between 1 and 12: ";
        cin >> num;
    }





    int i = 1;
    while (i <= 12) {
        cout << num << " times " << i << " is " << num * i << "." << endl;
        i++;
    }



    
    return 0;
}
