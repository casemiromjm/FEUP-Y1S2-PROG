#include <iostream>
#include "print_string.h"
#include <vector>
#include <string>

void split(const std::string& s, std::vector<std::string>& v){
    size_t pos = 0;

    while (pos < s.length())
    {
        if (s[pos] == ' ') {
            pos++;
            continue;
        }

        if (s[pos] != ' ') {
            size_t next_space = s.find(' ', pos);

            if (next_space == std::string::npos) {
                next_space = s.length();
            }

            std::string str_slice = s.substr(pos, next_space - pos);
            v.push_back(str_slice);
            pos = next_space + 1;
        }
    }
}

int main(void){

    { string s = "";
  vector<string> v;
  split(s, v);
  print(v); }

    { string s = "    ";
  vector<string> v;
  split(s, v);
  print(v); }

    { string s = "  a b  c ";
  vector<string> v;
  split(s, v);
  print(v); }

    { string s = "C++ LEIC FCUP FEUP";
  vector<string> v;
  split(s, v);
  print(v); }

    { string s = "       C++        ";
  vector<string> v;
  split(s, v);
print(v); }

    return 0;
}