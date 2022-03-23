//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0061_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0061_H

#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }

        int n = 0;  // 链表长度
        ListNode *tail;
        for (auto p = head; p != NULL; p = p->next) {
            tail = p;
            ++n;
        }


        k %= n;  // 关键一步，不要忘记！
        auto *prev = head;
        for (int i = 0; i < n - k - 1; ++i) {  // 找到第n-k个结点的前驱
            prev = prev->next;
        }

        // Rotate.
        tail->next = head;
        head = prev->next;
        prev->next = nullptr;

        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0061_H
