//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0025_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0025_H

#include "listnode.h"

class Problem0025 {
    // 经典算法，直接背诵：反序k个节点，需要反序(k-1)条链
    // for循环的条件语句必须有2个分号
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (auto p = dummy;;) {  // 反序[p+1:q]部分
            auto q = p;
            for (int i = 0; i < k && q; ++i) {
                q = q->next;
            }
            if (!q) {  // 当前段长不足k，终止操作
                break;
            }
            auto a = p->next;
            auto b = a->next;
            for (int i = 0; i < k - 1; ++i) {  // 反转(k-1)条链
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
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0025_H
