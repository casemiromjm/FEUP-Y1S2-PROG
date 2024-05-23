#include <iostream>
using namespace std;

// unsigned long elevate2(unsigned long expoent){
//     unsigned long res = 1;

//     for (int i = 1; i <= expoent; i++){
//         res *= 2;
//     }

//     return res;
// }

unsigned long next_mersenne(unsigned long n){
    // Mn = 2^n - 1
    unsigned long mersenne = 1;

    if (n == 0){
        return 0;
    }

    while (mersenne < n){   // loop until mersenne >= n (final result)
        mersenne = (mersenne << 1) + 1; // shifting left by 1 positions is the same as multiplying by 2
    }

    return mersenne;
}

int main(void){
    cout << next_mersenne(0) << '\n';
    cout << next_mersenne(1) << '\n';
    cout << next_mersenne(2) << '\n';
    cout << next_mersenne(4) << '\n';
    cout << next_mersenne(128) << '\n';
    cout << next_mersenne(4294967296UL) << '\n';

    return 0;
}