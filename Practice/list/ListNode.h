//
// Created by sucon on 6/26/2018.
//

#ifndef PRACTICE_LISTNODE_H
#define PRACTICE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

    ~ListNode() = default;
};

#endif //PRACTICE_LISTNODE_H
