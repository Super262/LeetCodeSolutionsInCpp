//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0148_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0148_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem0148 {
public:
    ListNode *sortList(ListNode *head) {  // 归并排序思想
        // https://www.acwing.com/solution/content/408/
        int n = 0;
        for (auto p = head; p; p = p->next) {
            ++n;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (int seg = 1; seg < n; seg *= 2) {  // 枚举分治段的长度
            auto current = dummy;
            for (int i = 1; i + seg <= n; i += 2 * seg) {
                auto p = current->next;  // 左分治段指针
                auto q = current->next;  // 右分治段指针
                for (int k = 1; k <= seg; ++k) {
                    q = q->next;
                }
                int pc = 0;  // 左计数器
                int qc = 0;  // 右计数器
                while (pc < seg && qc < seg && p && q) {
                    if (p->val < q->val) {
                        current->next = p;
                        p = p->next;
                        ++pc;
                    } else {
                        current->next = q;
                        q = q->next;
                        ++qc;
                    }
                    current = current->next;
                }
                while (pc < seg && p) {
                    current->next = p;
                    p = p->next;
                    ++pc;
                    current = current->next;
                }
                while (qc < seg && q) {
                    current->next = q;
                    q = q->next;
                    ++qc;
                    current = current->next;
                }
                current->next = q;  // 必须的步骤：接合链表
            }
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0148_H
