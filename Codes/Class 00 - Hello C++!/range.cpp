#include <iostream>
using namespace std;

int main(){
    /*
    a program that reads two integers a and b and 
    prints all numbers between a and b (closed interval). 
    */

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++){
        cout << i << ' ';
   }
    cout << "\n";

    return 0;
}