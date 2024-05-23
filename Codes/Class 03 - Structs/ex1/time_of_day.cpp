#include <iostream>
#include "time_of_day.h"
using namespace std;

time_of_day tick(time_of_day t){
    t.m += 1;

    if (t.m >= 60){
        t.h += 1;
        t.m = t.m - 60;
    }

    if (t.h >= 24){
        t.h = t.h - 24;
    }

    return t;
}

int main(){
    cout << tick({ 0, 0 }) << '\n';
    cout << tick({ 12, 30 }) << '\n';
    cout << tick({ 12, 59 }) << '\n';
    cout << tick({ 23, 59 }) << '\n';
    cout << tick(tick(tick({ 23, 59 }))) << '\n';
    return 0;
}