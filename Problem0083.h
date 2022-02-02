//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0083_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0083_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 经典算法，直接背诵
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        auto current = head;
        for (auto p = current->next; p; p = p->next) {
            if (p->val == current->val) {
                continue;
            }
            current->next = p;
            current = p;
        }
        current->next = nullptr;  // 将新链表从原链表中分离
        return head;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0083_H
