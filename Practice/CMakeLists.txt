cmake_minimum_required(VERSION 3.7.2)
project(Practice)

set(CMAKE_CXX_STANDARD 11)

add_executable(Practice main.cpp strings/strings_algo.cpp strings/strings_algo.h list/list_algo.cpp list/list_algo.h list/ListNode.h)
# add_executable(Practice /strings/string_algo_impl.cpp)