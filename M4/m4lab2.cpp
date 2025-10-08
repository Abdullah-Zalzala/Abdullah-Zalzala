/*
Abdullah Zalzala
10/8/2025
csc134
m4lab2
*/

#include <iostream>
using namespace std;


int main() {

    int length = 10;
    int Height = 10;
    string tile = "#";


cout << endl << endl;
cout << "Draw a rectangle" << endl;
cout << "Length: ";
cin >> length;
cout << "Height: ";
cin >> Height;
cout << "rectangle" << length << " x " << Height << endl;

    for (int i = 0; i < length; i++) {
        cout << tile;
    }
        cout << endl;

        int count = 0;
        while (count < length) {
            cout << tile;
            count ++;

        }
cout << endl;


for (int i = 0; i < Height; i++) {
    cout << tile <<endl;
}


cout << endl << endl;
cout << "rectangle " << length << " x " << Height << endl;

for (int i=0; i < Height; i++) {




for (int j=0; j < length; j++) {
    cout << tile;
}
cout << endl;
}





return 0;
}