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

unsigned long bell(unsigned long n){
    unsigned long parcel, total = 0;
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        for (unsigned long k = 0; k <= n-1; k++){
            parcel = bc(n-1, k) * bell(k);
            total += parcel;
        }
        return total;
    }
}

int main(void){
    cout << bell(0) << '\n';
    cout << bell(1) << '\n';
    cout << bell(2) << '\n';
    cout << bell(3) << '\n';
    cout << bell(4) << '\n';
    cout << bell(6) << '\n';
    return 0;
}