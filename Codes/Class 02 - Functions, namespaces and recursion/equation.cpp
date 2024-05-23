#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    int delta, solutions;

    delta = b*b - 4 * a * c;

    if (delta > 0){
        solutions = 2;
        x2 = (-b + sqrt(delta)) / (2*a);
        x1 = (-b - sqrt(delta)) / (2*a);
        return solutions;
    }
    
    else if (delta == 0){
        solutions = 1;
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = NAN;
        return solutions;
    }
    else{
        solutions = 0;
        x1 = x2 = NAN;
        return solutions;
    }
}


int main(void){
    double x1, x2;

    int r = solve_eq(1, 1, 0, x1, x2);
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, -2, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, 1, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';

    r = solve_eq(1, -1, 0, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';

    r = solve_eq(3, 4, -2, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';

    return 0;
}
