#include <iostream>
#include <vector>
#include "smatrix.h"

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t i = 0, j = 0;    // numbers to iterate through each non 0 element

    while (i < a.size() && j < b.size()) {
        if (a[i].row < b[j].row) {
            r.push_back(a[i]);
            i++;
            continue;
        }

        else if (b[j].row < a[i].row ) {
            r.push_back(b[j]);
            j++;
            continue;
        }

        else {      // a[i].row == b[j].row
            if (a[i].col < b[j].col) {
                r.push_back(a[i]);
                i++;
                continue;
            }
            else if (b[j].col < a[i].col) {
                r.push_back(b[j]);
                j++;
                continue;
            }

            else {
                sm_entry aux;
                aux.row = a[i].row;
                aux.col = a[i].col;
                aux.value = a[i].value + b[j].value;

                if (aux.value != 0) {
                    r.push_back(aux);
                }
                i++; j++;
            }
        }
    }

    while (i < a.size()) {
        r.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        r.push_back(b[j]);
        j++;
    }
}

int main(void) {

    { smatrix r;
  sum({ },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }
    
    { smatrix r;
  sum({ {0, 0, 1}, {1, 0, 1} },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }

    { smatrix r;
  sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
      r);
  print(r); }

    { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
      r);
  print(r); }

    { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
      r);
  print(r); }

    return 0;
}

    // while ( i < a.size() && j < b.size()){
    //     if (a[i].row < b[j].row){
    //         r.push_back(a[i++]);
    //     }

    //     else if (a[i].row > b[j].row){
    //         r.push_back(b[j++]);
    //     }

    //     else if (a[i].col < b[j].col){
    //         r.push_back(a[i++]);
    //     }

    //     else if (a[i].col > b[j].col){
    //         r.push_back(b[j++]);
    //     }

    //     else{
    //         int result = a[i].value + b[j].value;

    //         if (result != 0){
    //             r.push_back({a[i].row, a[i].col, result});
    //         }

    //         i++; j++;
    //     }
    // }

    // while (i < a.size()){
    //     r.push_back(a[i++]);
    // }

    // while (j < b.size()){
    //     r.push_back(b[j++]);
    // }