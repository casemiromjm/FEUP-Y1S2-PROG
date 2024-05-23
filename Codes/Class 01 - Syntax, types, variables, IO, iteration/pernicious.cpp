#include <iostream>
using namespace std;

bool prime(int numToCheck){
    int divisor;

    if (numToCheck <= 1){
        return false;
    }

    if (numToCheck <= 3){
        return true;
    }

    for (divisor = 2; divisor < numToCheck; divisor++){    // for loop that creates the divisor
        if (numToCheck % divisor == 0){
            return false;
        }
    }
    return true;
}

bool pernicious(int numToCheck){
    // 1º converter p/ binario -> usar bitwise operators
    // 2º analisar quantidade de 1s

    int count = 0;

    // check the number of 1s in a certain number
    while (numToCheck != 0){
        numToCheck &= (numToCheck-1);
        count++;
    }

    if (prime(count)){
        return true;
    }

    else{
        return false;
    }
}

int main(){
    int a, b; // low and high bound

    cin >> a >> b;

    for (int num = a; num <= b; num++){
        if (prime(num) && pernicious(num)){
            cout << num << ' ';
        }
    }

    cout << endl;
    return 0;
}