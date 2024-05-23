#include <iostream>
#include "complex.h"
using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

// precisou ter essa variavel auxiliar para funcionar, pq r está sendo referenciado (em algum iteração ele é estragado)
void mul(const complex& a, const complex& b, complex& r){
    complex aux;
    aux.x = (a.x*b.x) - (a.y*b.y);
    aux.y = (a.x*b.y) + (b.x*a.y);
    r = aux;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    if (n == 0){
        z_n.x = 0;
        z_n.y = 0;
    }
    
    else{
        mandelbrot(c, n-1, z_n);
        mul(z_n, z_n, z_n);
        add(z_n, c, z_n);
    }
}

int main(){

    { complex z_n;
    mandelbrot({1.2, 3.4}, 0, z_n);
    cout << z_n << '\n'; }

    { complex z_n;
    mandelbrot({1, 1}, 1, z_n);
    cout << z_n << '\n'; }

    { complex z_n;
    mandelbrot({1, 1}, 2, z_n);
    cout << z_n << '\n'; }

    { complex z_n;
    mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n'; }

    { complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n'; }

    { complex z_n;
    mandelbrot({-1, 0}, 11, z_n);
    cout << z_n << '\n'; }

    return 0;
}