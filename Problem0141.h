//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0141_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0141_H

#include <iostream>
#include "listnode.h"

using namespace std;

class Problem0141 {
    // 快慢指针：slow每次前进1步，fast每次前进2步；若两者相遇，说明有环
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0141_H
