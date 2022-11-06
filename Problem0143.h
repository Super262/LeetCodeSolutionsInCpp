//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0143_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0143_H

#include "listnode.h"

class Problem0143 {
    // 经典算法，必须掌握
    // 将链表分成两部分：[0:(n+1)/2-1]和[(n+1)/2:n]；翻转后半部分；将后半部分的节点插入到前半部分
public:
    void reorderList(ListNode *head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {  // 获得链表长度
            ++n;
        }
        if (n <= 2) {
            return;
        }
        auto later = head;
        for (int i = 0; i < (n + 1) / 2 - 1; ++i) {  // 找到索引为(n + 1) / 2 的点的前驱
            later = later->next;
        }
        auto a = later;
        auto b = later->next;
        while (b) {  // 翻转子序列[(n + 1) / 2, n - 1]
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        later->next->next = nullptr;  // 断开两个序列
        later->next = nullptr;
        while (head && a) {  // 将第2个序列的结点插入第1个序列
            auto temp = a->next;
            a->next = head->next;
            head->next = a;
            a = temp;
            head = head->next->next;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0143_H
