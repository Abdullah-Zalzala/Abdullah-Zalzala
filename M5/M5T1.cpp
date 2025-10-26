/*
Abdullah Z
10/22/2025
m5t1
*/
#include <iostream>
using namespace std;


void say_hello();

int get_the_answer();

double double_a_number(double);

int main() {

double my_num;
int another_num;

say_hello();
cout << " please enter a number with or without a decimal point: " << endl;
cin >> my_num;
my_num = my_num * 2;
cout << "double your number is: "<< my_num << endl;
cout << "but the only answer youll need is: ";
cout << get_the_answer() << endl;

    return 0;
}
void say_hello() {

    cout << "welcome to the best program ever!" << endl;
}

int get_the_answer() {

}

double double_a_number(double the_num){
    double answer = the_num * 2;
    return answer;
    return 0:
}