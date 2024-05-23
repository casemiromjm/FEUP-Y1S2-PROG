// n está feito

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

void trim(char s[]){

    for (int i = 0; i < len(s); i++){
        if (s[i] != ' '){

        }
    }
}

int main(){

    { char s[] = " abc! def? ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "#abc";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "abc def.   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = " abc  _  def  _  ghi ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    { char s[] = "a           ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n"; }

    return 0;
}