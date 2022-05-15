//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0234_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0234_H

#include"listnode.h"

class Solution {
    // 将链表前半段反序，再和后半段比较
    // 细节：链表长度可能为奇数，也可能为偶数
public:
    bool isPalindrome(ListNode *head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {  // Get the length
            ++n;
        }
        if (n < 2) {
            return true;
        }
        ListNode *a = nullptr;
        ListNode *b = head;
        ListNode *c = head->next;
        for (int i = 0; i < n / 2; ++i) {  // Reverse
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        auto p1 = a;
        auto p2 = n % 2 ? c : b;
        while (p1 || p2) {  // Iterate
            if (!p1 || !p2) {
                return false;
            }
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0234_H
