//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0525_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0525_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 类似于LeetCode 523题：设某子数组中"1"的个数是ones，"0"的个数是zeroes，t=ones-zeroes
    // 若子数组nums[i:j]中"0"的个数和"1"的个数相等，nums[0:j]的t和nums[0:i-1]的t相等
public:
    int findMaxLength(const vector<int> &nums) {
        unordered_map<int, int> prefix_idx;
        int ans = 0;
        prefix_idx[0] = 0;
        for (int i = 1, zeroes = 0, ones = 0; i <= (int) nums.size(); ++i) {
            if (nums[i - 1]) {
                ++ones;
            } else {
                ++zeroes;
            }
            auto t = ones - zeroes;
            if (prefix_idx.count(t)) {
                ans = max(ans, i - prefix_idx[t]);
            } else {
                prefix_idx[t] = i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0525_H
