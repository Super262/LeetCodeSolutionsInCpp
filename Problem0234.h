//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0234_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0234_H

class Problem0234 {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    bool isPalindrome(ListNode *head) {
        if (!head) {
            return true;
        }
        // Get the length.
        int n = 0;
        auto current = head;
        while (current) {
            ++n;
            current = current->next;
        }

        // Reverse
        auto left = head;
        auto right = head->next;
        ListNode *prev = nullptr;
        for (int i = 1; i <= n / 2; ++i) {
            left->next = prev;
            prev = left;
            left = right;
            right = right->next;
        }

        // Iterate.
        auto p1 = prev;
        auto p2 = n % 2 == 0 ? left : right;
        while (p1 && p2) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0234_H
