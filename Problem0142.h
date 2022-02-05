//
// Created by Fengwei Zhang on 11/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0142_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0142_H

#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    // 经典算法，直接背诵
    // https://www.acwing.com/solution/content/2946/
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0142_H
