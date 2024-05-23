#include <iostream>
#include "interval.h"
using namespace std;

int interval_in_minutes(const interval a){        // calculates how many minutes there are in an interval
    int minutes = 0;
    interval aux = a;

    minutes = (60 - aux.start.m);
    aux.start.h += 1;
    minutes = minutes + aux.end.m;
    minutes = minutes + ((aux.end.h - aux.start.h) * 60);

    return minutes;
}

bool in_interval(const time_of_day t, const interval range){        // checks if a certain time of day y is inside a determined interval
    if (t.h < range.start.h || t.h > range.end.h){
        return false;
    }
    
    if ((t.h == range.start.h && t.m < range.start.m) || (t.h == range.end.h && t.m >= range.end.m)){
        return false;
    }

    return true;
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    /*
    interval u -> union of intervals that contains t
    interval a[n] -> array of intervals that might contain t
    interval_in_minutes -> interval u in minutes
    */

    /*
    1st -> check if an interval of an array contains t
    2nd -> starts to compute interval u(nion)
    3rd -> compute interval u duration in minutes
    */

   int valid_times = 0, iter = 0;
   time_of_day aux_start, aux_end;

   for (int i = 0; i < n; i++){
        if (in_interval(t, a[i])){
            valid_times++;
            if (iter == 0){
                iter++;
                aux_start = a[i].start;
                aux_end = a[i].end;
            }
            else{
                if ((a[i].start.h < aux_start.h) || (a[i].start.h == aux_start.h && a[i].start.m < aux_start.m)){
                    aux_start = a[i].start;
                }
                if ((a[i].end.h > aux_end.h) || (a[i].end.h == aux_end.h && a[i].end.m > aux_end.m)){
                    aux_end = a[i].end;
                }
            }
        }
   }

    if (valid_times == 0){
        u = {t, t};
        return 0;
   }

    u = {aux_start, aux_end};

    return interval_in_minutes(u);
}

int main(){

    { const int n = 1;
    const time_of_day t = { 13, 00 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }

    { const int n = 2;
    const time_of_day t = { 14, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                          { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }

    { const int n = 2;
    const time_of_day t = { 12, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                          { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }

    { const int n = 2;
    const time_of_day t = { 15, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                          { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; }

    { const int n = 5;
    const time_of_day t = { 15, 15 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                        { { 14, 30 }, { 15, 30 } }, 
                        { { 15, 10 }, { 16, 10 } }, 
                        { {  9, 30 }, { 15, 15 } }, 
                        { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n'; } 

    return 0;
}