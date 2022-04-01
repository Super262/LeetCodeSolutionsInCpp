//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0817_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0817_H

#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode *head, const vector<int> &nums) {
        unordered_set<int> elements(nums.begin(), nums.end());
        int ans = 0;
        int cur = 0;
        for (auto p = head; p; p = p->next) {
            if (elements.count(p->val)) {
                ++cur;
            } else {
                if (cur) {
                    ++ans;
                    cur = 0;
                }
            }
        }
        if (cur) {
            ++ans;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0817_H
