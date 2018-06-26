//
// Created by sucon on 6/25/2018.
//

#include <algorithm>
#include <vector>
#include <cmath>
#include "strings_algo.h"
#include <string>
#include <stack>

bool strings_algo::is_palindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
    std::vector<char> s_chars;
    for (char c : s) {
        if (std::isalpha(c) || std::isdigit(c)) {
            s_chars.push_back(c);
        }
    }

    if (s_chars.empty()) {
        return false;
    }

    bool is_palid = true;
    auto mid = s_chars.size() / 2;
    for (int st = 0, ed = (int) (s_chars.size() - 1); st < mid && ed >= mid; ++st, --ed) {
        const char &c_st = s_chars[st];
        const char &c_ed = s_chars[ed];
        if (c_st == c_ed) {
            continue;
        } else {
            is_palid = false;
            break;
        }
    }

    return is_palid;
}

std::string strings_algo::longest_common_prefix(std::vector<std::string> &strs) {

    if (strs[0].length() == 1) {
        return std::string(1, strs[0].at(0));
    }

    // 1. first find the shortest string
    auto shortest_size = static_cast<int>(strs[0].length());
    std::string shortest_string = strs[0];
    for (const std::string &s : strs) {
        if (s.length() < shortest_size) {
            shortest_size = static_cast<int>(s.length());
            shortest_string = s;
        }
    }

    char first_char = strs[0].at(0);
    int last_pfx_idx = -1;
    for (int i = 0; i < shortest_size; ++i) { // i = index of each char
        bool is_prefix = true;
        for (int j = 0; j < strs.size(); ++j) {
            std::string each_string = strs[j];
            char each_char = each_string.at(i);
            if (each_char != first_char) {
                is_prefix = false;
                break;
            }
        }

        if (!is_prefix) {
            break;
        }

        last_pfx_idx = i;

        // protect from out-of-bounds ex
        if (last_pfx_idx < shortest_size - 1) {
            first_char = shortest_string.at(last_pfx_idx + 1);
        }
    }

    std::string common_pfx;
    if (last_pfx_idx == -1) {
        common_pfx = "";
    } else {
        if (last_pfx_idx < shortest_size) {
            common_pfx = shortest_string.substr(0, static_cast<unsigned long>(last_pfx_idx + 1));
        }
    }

    return common_pfx;
}

int strings_algo::str_str(std::string heystack, std::string needle) {
    if (heystack.empty() && needle.empty()) {
        return 0;
    }

    if (heystack.empty()) {
        return -1;
    }

    if (needle.empty()) {
        return 0;
    }

    auto ndl_len = static_cast<int>(needle.length());
    if (ndl_len == 0) {
        return 0;
    }

    int counter = 0;
    bool has = false;
    do {
        for (int i = counter; i < heystack.length(); ++i) {
            char c = heystack.at(i);
            if (c == needle.at(0)) {
                counter = i;
                break;
            }
        }

        if (counter + ndl_len > heystack.length()) {
            // break; no need to continue searching.
            break;
        }

        if (needle.at(ndl_len - 1) != heystack.at(counter + ndl_len - 1)) {
            // keep searching.
            ++counter;
            continue;
        }

        if (needle != heystack.substr(counter, ndl_len)) {
            // keep searching.
            ++counter;
            continue;
        } else {
            has = true;
            break;
        }
    } while (counter + ndl_len <= heystack.length());

    if (!has) {
        return -1;
    }

    return counter;
}

int strings_algo::atoi(std::string s) {
    if (s.empty()) {
        return 0;
    }

    // 1. find the index of the first non-zero digit.
    int first_seg_idx = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (std::isdigit(s.at(i)) && s.at(i) != '0') {
            first_seg_idx = i;
            break;
        }

        if (i == s.length() - 1) {
            return 0;
        }
    }

    // remove all zeros before first segment pos
    int it_count = 0;
    for (auto it = s.begin(); it_count < first_seg_idx; it_count++) {
        if (*(it) == '0') {
            if (std::isdigit(*(it + 1))) {
                s.erase(it);
            } else {
                return 0;
            }
        } else {
            ++it;
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (std::isdigit(s.at(i)) && s.at(i) != '0') {
            first_seg_idx = i;
            break;
        }

        if (i == s.length() - 1) {
            return 0;
        }
    }

    // 2. if the first segment appears character, then return 0;
    bool is_below_zero = false;
    if (first_seg_idx != 0) {
        int copy_fsi;
        if (s.at(first_seg_idx - 1) == '+') {
            is_below_zero = false;
            copy_fsi = first_seg_idx - 1;
        } else if (s.at(first_seg_idx - 1) == '-') {
            is_below_zero = true;
            copy_fsi = first_seg_idx - 1;
        } else {
            copy_fsi = first_seg_idx;
        }

        for (int i = 0; i < copy_fsi; ++i) {
            if (s.at(i) != ' ') {
                return 0;
            }
        }
    }

    std::string sint("");
    for (int i = first_seg_idx; i < s.length(); ++i) {
        if (std::isdigit(s.at(i))) {
            sint.append(1, s.at(i));
        } else {
            break;
        }
    }

    if (sint.empty()) {
        return 0;
    }

    if (!is_below_zero && sint.length() > 10) {
        return INT32_MAX;
    }

    if (is_below_zero && sint.length() > 10) {
        return INT32_MIN;
    }

    long tmp_long = std::stol(sint);
    if (!is_below_zero && tmp_long > 2147483647) {
        return 2147483647;
    }

    if (is_below_zero && -tmp_long < -2147483648) {
        return -2147483648;
    }

    int res = is_below_zero ? -((int) tmp_long) : (int) tmp_long;

    return res;
}
