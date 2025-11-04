/*
Abdullah Zalzala
10/4/2025
m5T2
*/

#include <iostream>
#include <math.h>
using namespace std;

void printResult(int number, int result){
cout << number << " squared= " << result << endl;
}

int growth(int number) {
int result = pow((double)2, (double)number);
return result;
}

int square(int number) {
    int result;
    result = number * number;
    return result;
}

int main(){
int number, result;

number = 1;
while (number <= 10){
result = growth(number);
printResult(number, result);
number++;
}

}