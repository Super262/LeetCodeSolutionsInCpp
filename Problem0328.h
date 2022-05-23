//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0328_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0328_H

#include "listnode.h"

class Solution {
    // 分别保存奇数点和偶数点，最后将2条链相连
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto odd_head = head;
        auto even_head = head->next;
        auto odd_tail = odd_head;
        auto even_tail = even_head;
        for (auto p = head->next->next; p; p = p->next) {
            odd_tail->next = p;
            odd_tail = p;
            if (p->next) {
                p = p->next;
                even_tail->next = p;
                even_tail = p;
            }
        }
        odd_tail->next = even_head;
        even_tail->next = nullptr;
        return odd_head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0328_H
