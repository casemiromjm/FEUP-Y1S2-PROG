#include <iostream>
using namespace std;

bool pangram(const string& s, string& m){
    int occurrences [26] = {0};

    for (auto letter : s) {
        letter = tolower(letter);

        if (isalpha(letter)) {
            occurrences[letter - 'a']++;
        }
    }

    m = "";
    for (size_t i = 0; i < 26; i++) {
        if (occurrences[i] == 0) {
            char letter = i + 'a';

            m += letter;
        }
    }

    if (m.empty()) { return true; }
    return false;
}

int main(void){

    { string s = "";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n"; }

    { string s = "The quick brown fox jumps over the lazy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

    { string s = "A quick brown fox jumps over a classy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

    { string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

    { string s = " Stu yZ abC GhI MnO pQr   ";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

    return 0;
}