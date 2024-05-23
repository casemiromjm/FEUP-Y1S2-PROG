#include <iostream>
using namespace std;

int main(){
    int n, number, divisor;
    bool prime;

    cin >> n;

    for (number = 2; number <= n; number++){    // for loop that creates the number that'll be analyzed
        prime = true;
        for (divisor = 2; divisor < number; divisor++){    // for loop that creates the divisor
            if (number % divisor == 0){
                prime = false;
            }
        }
        if (prime){
            cout << number << ' ';
        }
    }

    cout << endl;
    return 0;
}