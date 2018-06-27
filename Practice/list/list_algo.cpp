//
// Created by sucon on 6/26/2018.
//

#include <list>
#include "list_algo.h"

void list_algo::delete_node(ListNode *head, ListNode *node) {
    ListNode *cur_node = head;
    ListNode *pre_node = nullptr;
    do {
        if (cur_node->val == node->val) {
            if (pre_node != nullptr) {
                pre_node->next = cur_node->next;
            }
            cur_node = nullptr;
            break;
        } else {
            pre_node = cur_node;
            cur_node = head->next;
        }
    } while (cur_node);
}
