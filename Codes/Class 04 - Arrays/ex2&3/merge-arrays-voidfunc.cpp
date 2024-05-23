#include <iostream>
#include "print_array.h"
using namespace std;

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
    // c = a + b

    int index_a = 0, index_b = 0, index_c = 0;

    while (index_a < na && index_b < nb){
        if (a[index_a] < b[index_b]){
            c[index_c] = a[index_a];
            index_a++;
            index_c++;
        }

        else if (b[index_b] < a[index_a]){
            c[index_c] = b[index_b];
            index_b++;
            index_c++;
        }

        else if (a[index_a] == b[index_b]){
            c[index_c] = a[index_a];
            index_a++;
            index_c++;
            c[index_c] = b[index_b];
            index_b++;
            index_c++;
        }
    }

    while (index_b != nb){
        c[index_c] = b[index_b];
        index_b++;
        index_c++;
    }

    while (index_a != na){
        c[index_c] = a[index_a];
        index_a++;
        index_c++;
    }
}

int main(){

    { const int NA = 4, NB = 6;
    int a[NA] = { 1, 2, 4, 7};
    int b[NB] = { 0, 3, 5, 6, 8, 9};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); }

    { const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); }

    { const int NA = 2, NB = 3;
    int a[NA] = { 0, 1 };
    int b[NB] = { 2, 3, 4 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); }

    { const int NA = 3, NB = 2;
    int a[NA] = { 2, 3, 4 };
    int b[NB] = { 0, 1 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); }

    { const int NA = 15, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB); }

    return 0;
}