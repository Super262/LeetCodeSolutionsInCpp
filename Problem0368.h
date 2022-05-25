//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0368_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0368_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 我们将原问题转化为LIS问题：若不减序列nums任意项nums[i]满足nums[i]%nums[i-1]=0，由序列中元素构成的集合满足题目要求
    // f[i]表示以nums[i]结尾的、满足题目要求的集合的最大长度
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const auto n = (int) nums.size();
        int f[n];
        int last_idx = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] != 0) {
                    continue;
                }
                f[i] = max(f[j] + 1, f[i]);
            }
            if (f[last_idx] < f[i]) {
                last_idx = i;
            }
        }
        vector<int> ans;
        ans.emplace_back(nums[last_idx]);
        while (f[last_idx] > 1) {
            for (int i = 0; i < last_idx; ++i) {
                if (f[i] + 1 != f[last_idx] || nums[last_idx] % nums[i] != 0) {
                    continue;
                }
                ans.push_back(nums[i]);
                last_idx = i;
                break;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0368_H
