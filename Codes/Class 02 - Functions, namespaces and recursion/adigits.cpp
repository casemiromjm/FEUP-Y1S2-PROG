#include <iostream>
using namespace std;

int adigits(int a, int b, int c){
    int biggest, lowest, mid;

    biggest = (max(max(a, b), c));
    lowest = min(min(a, b), c);

    mid = ((a + b + c) - (biggest + lowest)) * 10;
    biggest = biggest * 100;

    return biggest + mid + lowest;
}

int main(){

    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';

    return 0;
}