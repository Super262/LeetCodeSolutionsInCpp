//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0147_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0147_H

#include "listnode.h"

class Solution {
    // 引入伪头节点，降低代码复杂度
public:
    ListNode *insertionSortList(ListNode *head) {
        auto *dummy = new ListNode(-1);
        while (head) {
            auto *t = head->next;
            auto *p = dummy;
            while (p->next && p->next->val <= head->val) {  // 寻找插入位置p，p->val <= head->val
                p = p->next;
            }
            head->next = p->next;  // 插入节点
            p->next = head;
            head = t;
        }
        auto ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0147_H
