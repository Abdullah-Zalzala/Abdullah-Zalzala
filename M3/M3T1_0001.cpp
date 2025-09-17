/*
Abdullah Zalzala
csc134
9/17/2025
M3T1
*/

#include <iostream>
using namespace std;

int main () {

    // get the intfo on the two rectangles
    double length1, length2, width1, width2;
    double area1, area2;
    cout << "enter the length and width of two rectangles." << endl;
    cout << "first rectangle." << endl;
    cout << "length: ";
    cin  >> length1;
    cout << "width: ";
    cin  >> width1;
    cout << endl;
    cout << "second rectangle." << endl;
    cout << "length: ";
    cin  >> length2;
    cout << "width: ";
    cin  >> width2;

    //calculate the area
    area1 = length1 * width1;
    area2 = length2 * width2;

    //print the output
    cout << "first rectngle area   = " << area1 << endl;
    cout << "second rectangle area = " << area2 << endl;

    // compare the two rectangles
    if (area1 > area2) {
        cout << "the first rectangle is larger." << endl;
    
    }
    if (area2 > area1) {
        cout << "the second rectangle is larger." << endl;
    }
    if (area1 == area2) {
        cout << "the rectangles have the same area" << endl;
    }
return 0; //no errors
}