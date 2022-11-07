//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0148_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0148_H

#include "listnode.h"

class Problem0148 {
    // 经典算法，直接背诵：链表的归并排序
    // https://www.acwing.com/solution/content/408/
public:
    ListNode *sortList(ListNode *head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {  // 求得链表的长度
            ++n;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (int seg = 1; seg < n; seg *= 2) {  // 枚举分治段的长度
            head = dummy;
            for (int i = 1; i + seg <= n; i += 2 * seg) {
                auto p = head->next;  // 左分治段的起点
                auto q = head->next;  // 右分治段的起点
                for (int k = 1; k <= seg; ++k) {
                    q = q->next;
                }
                int pc = 0;  // 左计数器
                int qc = 0;  // 右计数器
                while (pc < seg && qc < seg && p && q) {
                    if (p->val < q->val) {
                        head->next = p;
                        p = p->next;
                        ++pc;
                    } else {
                        head->next = q;
                        q = q->next;
                        ++qc;
                    }
                    head = head->next;
                }
                while (pc < seg && p) {
                    head->next = p;
                    p = p->next;
                    ++pc;
                    head = head->next;
                }
                while (qc < seg && q) {
                    head->next = q;
                    q = q->next;
                    ++qc;
                    head = head->next;
                }
                head->next = q;  // 必须的步骤：接合链表
            }
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0148_H
