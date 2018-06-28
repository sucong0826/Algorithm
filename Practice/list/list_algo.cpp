//
// Created by sucon on 6/26/2018.
//

#include <list>
#include <stack>
#include <vector>
#include <forward_list>
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

ListNode *list_algo::merge_two_lists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    } else if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }

    int l1_min = l1->val;
    int l1_size = 1;
    ListNode *l1_last_nd = l1;
    while (l1_last_nd->next != nullptr) {
        l1_last_nd = l1_last_nd->next;
        ++l1_size;
    }
    int l1_max = l1_last_nd->val;

    int l2_min = l2->val;
    int l2_size = 1;
    ListNode *l2_last_nd = l2;
    while (l2_last_nd->next != nullptr) {
        l2_last_nd = l2_last_nd->next;
        ++l2_size;
    }
    int l2_max = l2_last_nd->val;

    if (l1_min >= l2_max) {
        l2_last_nd->next = l1;
        return l2;
    }

    if (l1_max <= l2_min) {
        l1_last_nd->next = l2;
        return l1;
    }

    if (l1_size < l2_size) {
        ListNode *tmp = l1;
        l1 = l2;
        l2 = tmp;
    }

    ListNode *cur_l2_nd = l2;
    while (cur_l2_nd != nullptr) {

        ListNode *cur_l2_next_nd = l2->next;
        ListNode *cur_l1_nd = l1;

        while (cur_l1_nd != nullptr) {
            if (cur_l2_nd->val <= cur_l1_nd->val) {
                cur_l2_nd->next = cur_l1_nd;
                l1 = cur_l2_nd;
                break;
            } else if (cur_l2_nd->val > cur_l1_nd->val) {
                if (cur_l1_nd->next == nullptr) {
                    cur_l1_nd->next = cur_l2_nd;
                    break;
                } else {
                    if (cur_l2_nd->val <= cur_l1_nd->next->val) {
                        ListNode *l1_next = cur_l1_nd->next;
                        cur_l1_nd->next = cur_l2_nd;
                        cur_l2_nd->next = l1_next;
                        break;
                    } else {
                        cur_l1_nd = cur_l1_nd->next;
                        continue;
                    }
                }
            } else {
                cur_l1_nd = cur_l1_nd->next;
            }
        };

        cur_l2_nd = cur_l2_next_nd;
        l2 = cur_l2_next_nd;
    }

    return l1;
}
