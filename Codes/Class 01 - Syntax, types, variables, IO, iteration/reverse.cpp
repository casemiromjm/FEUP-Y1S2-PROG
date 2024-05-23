#include <iostream>
using namespace std;

int main(){
    int originalNumber, reversedNumber, parcel;

    cin >> originalNumber;

    reversedNumber = 0;
    
    while (originalNumber > 0){
        parcel = originalNumber % 10;
        originalNumber = originalNumber / 10;
        reversedNumber = reversedNumber * 10 + parcel;
    }

    cout << reversedNumber << endl;

    return 0;
}