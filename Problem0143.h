//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0143_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0143_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 经典算法，必须掌握
    // https://www.acwing.com/solution/content/240/
public:
    void reorderList(ListNode *head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {
            ++n;
        }
        if (n <= 2) {
            return;
        }
        // 找到索引为(n + 1) / 2 的点的前驱
        auto later = head;
        for (int i = 0; i < (n + 1) / 2 - 1; ++i) {
            later = later->next;
        }
        // 翻转子序列[(n + 1) / 2, n - 1]
        auto a = later;
        auto b = later->next;
        while (b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        // 断开两个序列
        later->next->next = nullptr;
        later->next = nullptr;
        // 将第2个序列的结点插入第1个序列
        while (head && a) {
            auto temp = a->next;
            a->next = head->next;
            head->next = a;
            a = temp;
            head = head->next->next;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0143_H
