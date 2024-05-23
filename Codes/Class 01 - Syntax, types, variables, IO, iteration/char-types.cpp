#include <iostream>
using namespace std;

int main(){
    // n is the length of the 'array' that will be analyzed
    int n, digits, letters, specials;
    char character;

    digits = 0;
    letters = 0;
    specials = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> character;

        if (character >= '0' and character <= '9'){ //char is a digit
            digits++;
        }

        else if ((character >= 'a' and character <= 'z') or (character >= 'A' and character <= 'Z')){ //char is a letter
            letters++;
        }

        else{ // char neither is digit nor letter
            specials++;
        }
    }

    cout << letters << ' ' << digits << ' ' << specials << endl;

    return 0;
}