//
// Created by sucon on 6/25/2018.
//

#ifndef PRACTICE_STRINGS_ALGO_H
#define PRACTICE_STRINGS_ALGO_H


#include <string>

class strings_algo {
public:
    strings_algo() = default;

    // check a string is a palindrome or not.
    bool is_palindrome(std::string s);

    // get the common prefix string from all strings.
    std::string longest_common_prefix(std::vector<std::string> &strs);

    // find the sub-string from heystack.
    int str_str(std::string heystack, std::string needle);

    // convert a string to integer.
    int atoi(std::string s);
};


#endif //PRACTICE_STRINGS_ALGO_H
