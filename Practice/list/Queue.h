//
// Created by sucon on 7/3/2018.
//

#ifndef PRACTICE_QUEUE_H
#define PRACTICE_QUEUE_H

#include "ListNode.h"

class Queue {
private:
    ListNode *first;
    ListNode *last;
    int len = 0;

public:

    Queue() = default;
    ~Queue();

    bool empty() {
        return len == 0;
    }

    int size() {
        return len;
    }

    // insert an element to tail.
    void enqueue(int i) {
        ListNode *old_last = last;
        ListNode nd(i);
        last = &nd;

        if (empty()) {
            first = last;
        } else {
            old_last->next = last;
        }

        ++len;
    }

    // delete an element from head.
    int dequeue() {
        int val = first->val;

        // delete the head
        first = first->next;
        if (empty()) {
            last = nullptr;
        }

        --len;
        return val;
    }
};

Queue::~Queue() = default;

#endif //PRACTICE_QUEUE_H
