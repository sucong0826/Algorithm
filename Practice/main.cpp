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

    std::vector<std::string> pfx_strings = {"dog", "racecar", "car"};
    std::string common_pfx = sa.longest_common_prefix(pfx_strings);
    std::cout << common_pfx << " is the common string pfx!" << std::endl;

    int pos = sa.str_str("mississippi", "pi");
    std::cout << "The ss pos is " << pos << std::endl;

    int stoi = sa.atoi("0-1");
    std::cout << "The stoi result is " << stoi << std::endl;

    std::array<int, 5> int_arr = {1, 2, 3};
    std::cout << "size is " << int_arr.size() << std::endl;

    ListNode n0(1), n1(2);
    n0.next = &n1;

    ListNode n5(1), n6(2), n7(4), n8(3), n9(2), n10(1);
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    n9.next = &n10;

    list_algo la;
    // la.delete_node(&n0, &n1);
//    ListNode *front = la.remove_node_from_end(&n0, 1);
//    std::cout << "The front node is " << front -> val << std::endl;

    // la.reverse_node(&n0);
    // la.recursive_reverse(&n0);

//    ListNode *res = la.merge_two_lists(&n0, &n5);
//    la.print_nd_list(res);

//    bool has_cycle = la.has_cycle(&n0);
//    std::string pal_str = has_cycle ? "True" : "False";
//    std::cout << pal_str << std::endl;

    ListNode *head = la.recursive_reverse(&n5);
    la.print_nd_list(head);

    return 0;
}
