#include <iostream>
using namespace std;

int main(){
    int n, num;

    cin >> n;

    for (num = 1; num <= n; num++){
        if (num % 3 == 0 and num % 5 == 0){
            continue;
        }
        else if (num % 3 == 0){
            cout << "Fizz";
        }
        else if (num % 5 == 0){
            cout << "Buzz";
        }
        else{
            cout << num;
        }
        cout << ' ';
    }

    return 0;
}