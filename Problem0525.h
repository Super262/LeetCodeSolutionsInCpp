//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0525_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0525_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 类似于LeetCode 523题
public:
    int findMaxLength(const vector<int> &nums) {
        unordered_map<int, int> prefix_idx;
        int res = 0;
        prefix_idx[0] = 0;
        for (int i = 1, zeros = 0, ones = 0; i <= nums.size(); ++i) {
            if (nums[i - 1]) {
                ++ones;
            } else {
                ++zeros;
            }
            auto t = ones - zeros;
            if (prefix_idx.count(t)) {
                res = max(res, i - prefix_idx[t]);
            } else {
                prefix_idx[t] = i;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0525_H
