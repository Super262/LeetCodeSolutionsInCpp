//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0203_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0203_H


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 引入dummy结点，统一操作
public:
    ListNode *removeElements(ListNode *head, const int &val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto left = dummy;
        auto right = dummy->next;
        while (right) {
            if (right->val == val) {
                right = right->next;
            } else {
                left->next = right;
                left = right;
                right = right->next;
            }
        }
        left->next = right;
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0203_H
