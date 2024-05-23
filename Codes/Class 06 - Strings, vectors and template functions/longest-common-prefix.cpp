#include <iostream>
#include <string>
#include <vector>

std::string longest_prefix(const std::vector<std::string>& v){

    if (v.empty()) { return ""; }

    std::string shortest_word = v[0];
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i].length() < shortest_word.length()) { shortest_word = v[i]; }
    }

    std::string prefix = "";
    for (size_t i = 0; i < shortest_word.length(); i++) {
        char current_letter = shortest_word[i];

        for (const std::string& word : v) {
            if (word == shortest_word) { continue; }

            if (current_letter != word[i]) { return prefix; }
        }

        prefix += current_letter;
    }
    
    return prefix;
}

int main(){

    std::cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";

    std::cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";

    std::cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";

    std::cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";

    std::cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";

    return 0;
}

    // if (v.empty()){ return ""; }

    // std::string shortest = v[0];
    // for (const std::string& word : v){
    //     if (word.length() < shortest.length()){
    //         shortest = word;
    //     }
    // }

    // std::string prefix = "";
    // for (size_t i = 0; i < shortest.length(); i++){
    //     char current_char = shortest[i];

    //     for (const std::string& s : v){
    //         if (s[i] != current_char){
    //             return prefix;
    //         }
    //     }

    //     prefix.push_back(current_char);
    // }

    // return prefix;