//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0141_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0141_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        auto slow = head;
        auto fast = head->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0141_H
