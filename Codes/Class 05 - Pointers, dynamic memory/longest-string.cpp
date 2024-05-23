#include <iostream>
using namespace std;

int len(const char word[]){
    int res = 0, index = 0;
    while (word[index] != '\0'){
        res++;
        index++;
    }

    return res;
}

const char* longest(const char* pa[]){
    // returns de longest word in the array. if 2 words has the same length, it should return the rightmost

    char *res = NULL;
    int max = 0;

    for (int i = 0; pa[i] != nullptr; i++){
      if (len(pa[i]) >= max){
        max = len(pa[i]);
        res = (char *) pa[i];
      }
    }
    
    return res;
}

int main(){

    { const char* pa[] = { "C++", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }

    { const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }

    { const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }

    { const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }

    { const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }

    return 0;
}