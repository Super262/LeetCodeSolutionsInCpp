//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0817_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0817_H

#include <vector>
#include <unordered_set>
#include "listnode.h"

using namespace std;

class Problem0817 {
public:
    int numComponents(ListNode *head, const vector<int> &nums) {
        unordered_set<int> elements(nums.begin(), nums.end());
        int ans = 0;
        int cur_size = 0;
        for (auto p = head; p; p = p->next) {
            if (elements.count(p->val)) {
                ++cur_size;
                continue;
            }
            if (cur_size) {
                ++ans;
                cur_size = 0;
            }
        }
        if (cur_size) {
            ++ans;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0817_H
