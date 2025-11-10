/*
Abdullah Zalzala
11/6/2025
csc134
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
const int SIZE = 3;
int temps[SIZE];

for (int i=0; i < SIZE; i++) {
cout << "enter temp #" << i << ": ";
cin >> temps[i];
}
for (int i=0; i < SIZE; i++) {
cout << "temp #" << i << "=" << temps[i] << endl;
}

int count = 0;
while (count < SIZE) {
cout << "temp# " << count << '=' << temps[count] << endl;
count++;
} while (count < SIZE);


}