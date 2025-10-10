/*
Abdullah Zalzala
10/9/2025
csc134
m4t1
*/

#include <iostream>
#include <string>

using namespace std;

int main () { 

int number = 5;

int i = 0;
while (i < number) {
    cout << "Hello World" << endl;
    i++;


}

 cout << "thats all!" << endl;


const int MUN_NUMBER = 1;
const int MAX_NUMBER = 10;

int num = MUN_NUMBER;

cout << "number\tnumber Squared" << endl;

while (num <= MAX_NUMBER) {


    cout << num << "\t\t" << (num * num) << endl;
    num++;
}

return 0;
}