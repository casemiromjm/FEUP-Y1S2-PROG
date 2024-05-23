#include <iostream>
using namespace std;

bool is_leap_year(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return true;
    }
    return false;
}

int days_in_month(int month, int year){
    int days;
    enum {jan = 1, feb, mar, abr, may, jun, jul, ago, sep, out, nov, dec};
    switch(month){
        case feb:
            days = is_leap_year(year) ? 29 : 28;
            break;
        case jan: case mar: case may: case jul: case ago: case out: case dec:
            days = 31;
            break;
        default:
            days = 30;
            break;
    }
    return days;
}

void advance(int delta, int& d, int& m, int& y){
    enum {jan = 1, feb, mar, abr, may, jun, jul, ago, sep, out, nov, dec};

    d += delta;

    while (d > days_in_month(m, y)){
        d -= days_in_month(m, y);

        if (m == dec){
            m = jan;
            y++;
        }
        else{
            m++;
        }
    }
}

int main(void){
    int d = 1, m = 1, y = 2022; 
    advance(0, d, m, y); 
    cout << d << ' ' << m << ' ' << y << endl;

    d = 1, m = 10, y = 2022; 
    advance(10, d, m, y); 
    cout << d << ' ' << m << ' ' << y << endl;

    d = 2, m = 6, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    d = 2, m = 7, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    d = 25, m = 2, y = 2000; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    d = 25, m = 2, y = 2001; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    d = 2, m = 12, y = 1900; 
    advance(365 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    d = 31, m = 3, y = 1903; 
    advance(365 + 366 + 30 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';

    return 0;
}