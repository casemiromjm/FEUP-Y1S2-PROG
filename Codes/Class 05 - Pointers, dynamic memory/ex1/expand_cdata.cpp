#include <iostream>
#include "cdata.h"
using namespace std;

int* expand_cdata(const cdata a[], int n){
    int arr_len = 0;
    for (int i = 0; i < n; i++){
        arr_len += a[i].count;
    }

    int *expanded_arr = new int[arr_len];

    int arr_index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i].count; j++){
            expanded_arr[arr_index] = a[i].value;
            arr_index++;
        }
    }

    return expanded_arr;
}

int main(){

    { const int n = 1;
    const cdata a[] { { 3, 999 } };
    int* r = expand_cdata(a, n);
    print_array(r, 3);
    delete [] r; }

    { const int n = 3;
    const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
    int* r = expand_cdata(a, n);
    print_array(r, 6);
    delete [] r; }

    { const int n = 1;
    const cdata a[] { { 1, 999 } };
    int* r = expand_cdata(a, n);
    print_array(r, 1);
    delete [] r; }

    { const int n = 2;
    const cdata a[] { { 20, 1 }, { 17, 2} };
    int* r = expand_cdata(a, n);
    print_array(r, 37);
    delete [] r; } 

    { const int n = 4;
    const cdata a[] { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
    int* r = expand_cdata(a, n);
    print_array(r, 13);
    delete [] r; }

    return 0;
}