#include <iostream>
using namespace std;

unsigned long power(unsigned long base, int exponent){
    unsigned long res = 1;
    for (int i = 0; i < exponent; i++){
        res = res * base;
    }
    return res;
}

int len(const char word[]){
    int res = 0, index = 0;
    while (word[index] != '\0'){
        res++;
        index++;
    }

    return res;
}

unsigned long hstr_to_integer(const char hstr[]){
    int index = 0;
    unsigned long decimal_res = 0, add_num = 0;

    int length = len(hstr);

    while (hstr[index] != '\0'){
        if ((hstr[index] >= 'a' && hstr[index] <= 'f')){
            add_num = hstr[index] - 87;
            decimal_res += (add_num * power(16, length - index - 1));   // precisa do -1 pq o len é sempre 1 maior q os index
        }
        else if ((hstr[index] >= 'A' && hstr[index] <= 'F')){
            add_num = hstr[index] - 55;
            decimal_res += (add_num * power(16, length - index - 1));
        }
        else if (hstr[index] >= '0' && hstr[index] <= '9'){
            add_num = hstr[index] - 48;
            decimal_res += (add_num * power(16, length - index - 1));
        }

        index++;
    }

    return decimal_res;
}

int main(){

    cout << hstr_to_integer("0") << endl;
    cout << hstr_to_integer("A") << endl;
    cout << hstr_to_integer("19") << endl;
    cout << hstr_to_integer("fF") << endl;
    cout << hstr_to_integer("CafeBabe2022") << endl;

    return 0;
}