#include <iostream>
#include <vector>
#include <algorithm>
#include "strings/strings_algo.h"
#include <array>


int main() {
    std::cout << "Hello, World!" << std::endl;

    strings_algo sa;
    bool is_pal = sa.is_palindrome("race a car");
    std::string is_pal_str = is_pal ? "True" : "False";
    std::cout << is_pal_str << std::endl;

    std::vector<std::string> pfx_strings = {"dog","racecar","car"};
    std::string common_pfx = sa.longest_common_prefix(pfx_strings);
    std::cout << common_pfx << " is the common string pfx!" << std::endl;

    int pos = sa.str_str("mississippi", "pi");
    std::cout << "The ss pos is " << pos << std::endl;

    int stoi = sa.atoi("0-1");
    std::cout << "The stoi result is " << stoi << std::endl;

    std::array<int, 5> int_arr = {1, 2, 3};
    std::cout << "size is " << int_arr.size() << std::endl;

    return 0;
}
