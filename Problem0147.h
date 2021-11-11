//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0147_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0147_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        auto *dummy = new ListNode(-1);  // dummy后没有结点，插入排序从头部开始
        while (head) {
            auto *hnext = head->next;
            auto *p = dummy;
            while (p->next && p->next->val <= head->val) {
                p = p->next;
            }
            head->next = p->next;
            p->next = head;
            head = hnext;
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0147_H
