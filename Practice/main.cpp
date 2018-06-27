#include <iostream>
#include <vector>
#include <algorithm>
#include "strings/strings_algo.h"
#include "list/ListNode.h"
#include "list/list_algo.h"
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

    ListNode n3(9), n2(1), n1(5), n0(4);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    list_algo la;
    la.delete_node(&n0, &n1);

    return 0;
}
