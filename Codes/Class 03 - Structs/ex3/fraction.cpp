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

fraction mul(fraction a, fraction b){
    fraction res;
    int common_divisor;

    res.den = a.den * b.den;
    res.num = a.num * b.num;

    if (res.den == res.num){
        res.den = res.num = 1;
    }

    // simplify the fraction
    common_divisor = gcd(res.den, res.num);
    res.den = res.den / common_divisor;
    res.num = res.num / common_divisor;

    if (res.den < 0){
        res.den = -1*res.den;
        res.num = -1*res.num;
    }

    return res;
}

int main(){
    { fraction a { 0, 1 }, b { 2, 1};
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { 1, 1 }, b { -1, 2};
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -3, 2 }, b { 3, 2 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -3, 2 }, b { -2, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -7, 24 }, b { 1, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    { fraction a { -8, 25 }, b { 3, 4 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

    cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';

    return 0;
}