//
// Created by Fengwei Zhang on 5/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0325_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0325_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(const vector<int> &nums, int k) {
        unordered_map<long, int> first_idx;
        int ans = 0;
        long p = 0;
        first_idx[p] = 0;
        for (int i = 1; i <= (int) nums.size(); ++i) {
            p += nums[i - 1];
            if (first_idx.count(p - k)) {
                ans = max(i - first_idx[p - k], ans);
            }
            if (!first_idx.count(p)) {
                first_idx[p] = i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0325_H
