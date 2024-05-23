#include <iostream>
using namespace std;

int nrl(const char s[], char low[]){
    int counter [26] = {0};

    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == 'a' || s[i] == 'A'){ counter[0] += 1;}
        else if (s[i] == 'b' || s[i] == 'B'){counter [1] += 1;}
        else if (s[i] == 'c' || s[i] == 'C'){counter [2] += 1;}
        else if (s[i] == 'd' || s[i] == 'D'){counter [3] += 1;}
        else if (s[i] == 'e' || s[i] == 'E'){counter [4] += 1;}
        else if (s[i] == 'f' || s[i] == 'F'){counter [5] += 1;}
        else if (s[i] == 'g' || s[i] == 'G'){counter [6] += 1;}
        else if (s[i] == 'h' || s[i] == 'H'){counter [7] += 1;}
        else if (s[i] == 'i' || s[i] == 'I'){counter [8] += 1;}
        else if (s[i] == 'j' || s[i] == 'J'){counter [9] += 1;}
        else if (s[i] == 'k' || s[i] == 'K'){counter [10] += 1;}
        else if (s[i] == 'l' || s[i] == 'L'){counter [11] += 1;}
        else if (s[i] == 'm' || s[i] == 'M'){counter [12] += 1;}
        else if (s[i] == 'n' || s[i] == 'N'){counter [13] += 1;}
        else if (s[i] == 'o' || s[i] == 'O'){counter [14] += 1;}
        else if (s[i] == 'p' || s[i] == 'P'){counter [15] += 1;}
        else if (s[i] == 'q' || s[i] == 'Q'){counter [16] += 1;}
        else if (s[i] == 'r' || s[i] == 'R'){counter [17] += 1;}
        else if (s[i] == 's' || s[i] == 'S'){counter [18] += 1;}
        else if (s[i] == 't' || s[i] == 'T'){counter [19] += 1;}
        else if (s[i] == 'u' || s[i] == 'U'){counter [20] += 1;}
        else if (s[i] == 'v' || s[i] == 'V'){counter [21] += 1;}
        else if (s[i] == 'w' || s[i] == 'W'){counter [22] += 1;}
        else if (s[i] == 'x' || s[i] == 'X'){counter [23] += 1;}
        else if (s[i] == 'y' || s[i] == 'Y'){counter [24] += 1;}
        else if (s[i] == 'z' || s[i] == 'Z'){counter [25] += 1;}
    }

    int index = 0;
    for (int i = 0; i < 26; i++){
        if (counter[i] == 1){
            char aux = 'a' + i;
            low[index] = aux;
            index++;
        }
    }
    low[index] = '\0';
    return index;
} 

int main(){

    { const char s[] = "";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }

    { const char s[] = "  F C U P  F E U P  Porto  ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }

    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
    << r << " \"" << l << "\"\n"; }

    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }

    { const char s[] = "The quick brown fox jumps over the lazy dog";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }

    return 0;
}