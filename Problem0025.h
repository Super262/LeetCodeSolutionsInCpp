//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0025_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0025_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy;;) { // for循环的条件语句必须有2个分号
            auto q = p;
            for (int i = 0; i < k && q; ++i) {
                q = q->next;
            }
            if (!q) {
                break;
            }
            auto a = p->next;
            auto b = a->next;
            for (int i = 0; i < k - 1; ++i) {  // 反转(k-1)条边
                auto t = b->next;
                b->next = a;
                a = b;
                b = t;
            }
            auto c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0025_H
