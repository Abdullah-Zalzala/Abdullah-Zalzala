/*
Abdullah Zalzala
11/10/2025
csc134
m6t1.cpp
*/


#include <iostream>
#include <string>

using namespace std;
void method1();
void method2();

int main() {
    method1();
    method2();
    return 0;
}




void method1() {
    cout << "enter each pokemon found per day." << endl;
    cout << "Day 0 = monday, Day 4 = friday" << endl;
    const int SIZE = 5;
    int count = 0;
    int poke_today;
    int poke_total = 0;
    double poke_avg = 0;


    while (count < SIZE) {
        cout << "day" << count << ": ";
        cin >> poke_today;
        poke_total += poke_today;
        count++;
    }

}

void method2() {

    const int SIZE = 5;
    string days[SIZE] = {"M", "T", "W", "Th", "F"};
    int pokemon[SIZE];
    int poke_total = 0;
    double poke_avg = 0.0;


    for (int i = 0; i < SIZE; i++) {
        cout << "# on " << days[i] << ": ";
        cin >> pokemon[i];
   }



   cout << "day\tpokemon" << endl;
   for (int i = 0; i < SIZE; i++) {
       cout << days[i] << "\t" << pokemon[i] << endl;
       poke_total += pokemon[i];
   }

poke_avg = (double) poke_total / SIZE;
cout << "total = " << poke_total << endl;
cout << "average = " << poke_avg << endl;


}