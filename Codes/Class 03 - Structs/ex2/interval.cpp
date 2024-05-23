#include <iostream>
#include "interval.h"
using namespace std;

// 1o faz considerando q o intervalo a é sempre antes do b
// dps faz a validação caso o intervalo a seja depois do b

void interval_check(interval& a, interval& b){
    interval temp;
    if (a.start.h > b.start.h){
        temp = a;
        a = b;
        b = temp;
    }
    else if (b.start.h == a.start.h && a.start.m > b.start.m){
        temp = a;
        a = b;
        b = temp;
    }
}

interval intersection(interval a, interval b){
    interval res;

    // as a convention, I considered that interval "a" always comes first and, when not, I fix it
    interval_check(a, b);   // fix intervals if interval b comes before interval a

    if ((b.start.h > a.end.h) || (b.start.h == a.end.h && b.start.m >= a.end.m)){
        res.start = res.end = {0, 0};
        return res;
    }

    res.start = b.start;

    if ((b.end.h < a.end.h) || (b.end.h == a.end.h && b.end.m < a.end.m)){
        res.end = b.end;
        return res;
    }
    else{
        res.end = a.end;
        return res;
    }
}

int main(){
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n';

    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n';

    cout << intersection( { { 12, 30 }, { 14, 31 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n';

    cout << intersection( { { 14, 30 }, { 15, 59 } },
                        { { 11, 30 }, { 14, 31 } } ) << '\n';

    cout << intersection( { {  4, 30 }, {  7, 59 } },
                        { {  4,  0 }, {  7, 29 } } ) << '\n';

    cout << intersection( { { 23,  0 }, { 23, 58 } },
                        { { 22, 45 }, { 23, 59 } } ) << '\n';

    return 0;
}