//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0523_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0523_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 目标：找到一个长度不小于2的区间 [i-1, j] ，使 (prefix[j] - prefix[i-1]) % k == 0 成立（j > i）
    // 利用性质：若 a - b = k * x，则 a % x == b % x 成立
public:
    bool checkSubarraySum(const vector<int> &nums, int k) {
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        prefix[1] = nums[0];
        unordered_set<int> remainders;
        for (int i = 2; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            remainders.insert(prefix[i - 2] % k);
            if (remainders.count(prefix[i] % k)) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0523_H
