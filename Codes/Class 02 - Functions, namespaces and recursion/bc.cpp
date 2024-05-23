#include <iostream>
using namespace std;

unsigned long factorial(unsigned long n){
    if (n == 1 || n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

unsigned long bc(unsigned long n, unsigned long k){
    return (factorial(n)) / (factorial(k) * factorial(n-k));
}

int main(void){
    cout << bc(5, 0) << '\n';
    cout << bc(5, 1) << '\n';
    cout << bc(5, 5) << '\n';
    cout << bc(5, 2) << '\n';
    cout << bc(12, 7) << '\n';
    cout << bc(20, 10) << '\n';
    return 0;
}