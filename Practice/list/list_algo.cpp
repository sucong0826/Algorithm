//
// Created by sucon on 6/26/2018.
//

#include <list>
#include <stack>
#include <vector>
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

ListNode *list_algo::remove_node_from_end(ListNode *node, int n) {
    std::list<ListNode *> nodes;
    ListNode *cur_node = node;

    do {
        nodes.push_back(cur_node);
        cur_node = cur_node->next;
    } while (cur_node);

    if (nodes.empty()) {
        return nullptr;
    }

    if (nodes.size() == 1) {
        return nullptr;
    }

    int end_cnt = 0;
    int real_n = n - 1;
    std::list<ListNode *>::reverse_iterator it;
    for (it = nodes.rbegin(); it != nodes.rend();) {
        if (end_cnt == real_n) {
            if (end_cnt == 0) {
                // head node or end node, delete directly.
                (*++it)->next = nullptr;
                *(--it) = nullptr;
                it = std::list<ListNode *>::reverse_iterator(nodes.erase((++it).base()));
            } else if (end_cnt == nodes.size() - 1) {
                // delete first head
                *(it) = nullptr;
                it = std::list<ListNode *>::reverse_iterator(nodes.erase((++it).base()));
            } else {
                // we should still delete the node, but re-compose these nodes before deleting it.
                ListNode *pre_node = *(++it);
                pre_node->next = (*(--it))->next;
                *(it) = nullptr;
                it = std::list<ListNode *>::reverse_iterator(nodes.erase((++it).base()));
            }
            break;
        } else {
            ++it;
        }

        end_cnt++;
    }

    return nodes.front();
}

ListNode *list_algo::reverse_node(ListNode *nodes) {

    if (nodes == nullptr) {
        return nullptr;
    }

    std::stack<ListNode *> stack_nodes;
    do {
        stack_nodes.push(nodes);
        nodes = nodes->next;
    } while (nodes != nullptr);

    // first reversed node
    ListNode *top = nullptr, *root = stack_nodes.top();
    ListNode *pre = nullptr;

    do {
        top = stack_nodes.top();
        if (top->next != nullptr) {
            // first of all, cut the relation off.
            top->next = nullptr;
            pre->next = top;
        }
        stack_nodes.pop();
        pre = top;
    } while (!stack_nodes.empty());

    return root;
}

ListNode *list_algo::recursive_reverse(ListNode *nodes) {
    if (nodes == nullptr || nodes->next == nullptr) {
        return nodes;
    }

    ListNode *h = reverse(nodes);
    nodes->next = nullptr;
    return h;
}

ListNode *list_algo::reverse(ListNode *node) {
    if (node->next->next != nullptr) {
        ListNode *h = reverse(node->next);
        node->next->next = node;
        return h;
    } else {
        node->next->next = node;
        return node->next;
    }
}
