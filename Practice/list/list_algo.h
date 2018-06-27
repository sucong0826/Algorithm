//
// Created by sucon on 6/26/2018.
//

#ifndef PRACTICE_LIST_ALGO_H
#define PRACTICE_LIST_ALGO_H


#include "ListNode.h"

class list_algo {
public:
    void delete_node(ListNode *head, ListNode *node);
    ListNode* remove_node_from_end(ListNode *node, int n);
    ListNode* reverse_node(ListNode* nodes);
    ListNode* recursive_reverse(ListNode* nodes);

private:
    ListNode* reverse(ListNode *node);
};


#endif //PRACTICE_LIST_ALGO_H
