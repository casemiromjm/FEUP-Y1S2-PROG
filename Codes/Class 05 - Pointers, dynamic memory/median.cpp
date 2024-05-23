#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n){
    int* temp_arr = new int[n];
    int median;

    for (int i = 0; i < n; i++){    // copy elements
        temp_arr[i] = a[i];
    }

    sort(temp_arr, temp_arr + n);

    if (n % 2 != 0){
        median = temp_arr[n/2];
    }
    else{
        median = (temp_arr[n/2 - 1] + temp_arr[n/2])/2;
    }

    delete [] temp_arr;
    return median;
}

int main(){
    
    { const int n = 5; 
    int a[n] { 10, -10, 0, 12, 11 };
    cout << median(a, n) << '\n'; }

    { const int n = 6; 
    int a[n] { 30, 10, 0, -20, 14, 20 };
    cout << median(a, n) << '\n'; }

    { const int n = 1; 
    int a[n] { 99 };
    cout << median(a, n) << '\n'; }

    { const int n = 2; 
    int a[n] { 101, 99 };
    cout << median(a, n) << '\n'; }

    return 0;
}