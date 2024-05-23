#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    // k is the approximation (the parcel to sum)
    // d is the decimal places approximation

    int k, d;
    double parcel, pi_approx;

    cin >> k >> d;

    for (int i = 0; i <= k; i++){
        parcel = pow(-1, i) / (2*i + 1);
        pi_approx += parcel;
    }

    pi_approx = 4 * pi_approx;

    cout << fixed << setprecision(d) << pi_approx << "\n";

    return 0;
}