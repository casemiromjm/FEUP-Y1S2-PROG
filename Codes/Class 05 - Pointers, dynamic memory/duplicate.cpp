#include <iostream>
using namespace std;

int len(const char word[]){
    int res = 0, index = 0;
    while (word[index] != '\0'){
        index++;
    }
    res = index;
    return res;
}

char* duplicate(const char s[]){
    int size = len(s);

    char *copy = new char[size + 1];

    for (int i = 0; i <= size; i++){
        copy[i] = s[i];
    }

    return copy;
}

int main(){
    
    { char* s = duplicate("");
    cout << "\"" << s << "\"\n";
    delete [] s; }

    { char* s = duplicate("a");
    cout << "\"" << s << "\"\n";
    delete [] s; }

    { char* s = duplicate("C++");
    cout << "\"" << s << "\"\n";
    delete [] s; }

    { char* s = duplicate("0123 456 789 @ abc");
    cout << "\"" << s << "\"\n";
    delete [] s; }

    return 0;
}