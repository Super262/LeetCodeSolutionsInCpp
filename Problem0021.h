//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0021_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0021_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        auto dummy = new ListNode(-1);
        dummy->next = l1;
        auto res_cur = dummy;
        auto l2_cur = l2;
        ListNode *l2_next;
        while (l2_cur && res_cur->next) {
            if (res_cur->next->val >= l2_cur->val) {
                l2_next = l2_cur->next;
                l2_cur->next = res_cur->next;
                res_cur->next = l2_cur;
                l2_cur = l2_next;
            } else {
                res_cur = res_cur->next;
            }
        }
        if (l2_cur) {
            res_cur->next = l2_cur;
        }
        return dummy->next;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0021_H
