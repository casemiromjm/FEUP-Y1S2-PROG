#include <vector>
#include "print_vector.h"       // as this header already includes vector and iostream and uses namespace std, so I wouldn't need to use std:: or include iostream and vector

template <typename T>
void normalise(std::vector<T>& v, const T& min, const T& max){
    for (auto& element : v) {
        if (element > max) { element = max; continue; }
        if (element < min) { element = min; continue; }
    }
}

int main(void) {

    { vector<int> v { }; normalise(v, 0, 1); print(v); }

    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 1, 5); print(v); }

    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 3, 4); print(v); }

    { vector<double> v { -1.2, 2.2, -3.5, 4.3, 5.2 }; 
  normalise(v, 0.5, 5.1); print(v); }

    { vector<string> v { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
  normalise(v, string("Antonio"), string("Zacarias")); print(v); }
    
    return 0;
}