#include <iostream>
#include "fraction.h"
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

fraction add(fraction a, fraction b){
    fraction res;
    int common_divisor;

    // if denominators are equal, you just need to sum the numerators
    if (a.den == b.den){
        res.den = a.den;
        res.num = a.num + b.num;
    }

    // if denominators are different
    else{
        res.den = (a.den * b.den) / gcd(a.den, b.den);
        res.num = (a.num * (res.den / a.den)) + (b.num * (res.den / b.den));
    }

    if (res.den == 0){
        res.den = 1;
    }

    // simplify the fraction
    common_divisor = gcd(res.den, res.num);
    res.den = res.den / common_divisor;
    res.num = res.num / common_divisor;

    if (res.den <= -1){
        res.den = -1*res.den;
        res.num = -1*res.num;
    }

    return res;
}

fraction sum(const fraction fa[], int n){
    fraction prev, curr;
    
    if (n == 1){return fa[0];}

    prev = add(fa[0], fa[1]);

    if (n == 2){return prev;}

    for (int i = 2; i < n; i++){
        curr = add(prev, fa[i]);
        prev = curr;
    }
    
    return curr;
}

int main(){

    { const int n = 1;
    const fraction fa[n] { {1, 2} };
    cout << sum(fa, n) << '\n'; }

    { const int n = 2;
    const fraction fa[n] { {1, 2}, {-1, 3} };
    cout << sum(fa, n) << '\n'; }

    { const int n = 3;
    const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
    cout << sum(fa, n) << '\n'; }

    { const int n = 4;
    const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
    cout << sum(fa, n) << '\n'; }

    { const int n = 5;
    const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa, n) << '\n'; }

    { const int n = 6;
    const fraction fa[n] { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
    cout << sum(fa, n) << '\n'; }

    return 0;
}