//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0876_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0876_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 快慢指针；注意：奇数长度、偶数长度的边界情况不同
public:
    ListNode *middleNode(ListNode *head) {
        auto p = head;
        auto q = head;
        while (q && q->next) {  // 偶数长度：q空；奇数长度：q->next空
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0876_H
