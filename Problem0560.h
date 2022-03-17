//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0560_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0560_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典操作：双指针 + 哈希表
public:
    int subarraySum(const vector<int> &nums, int k) {
        int result = 0;
        int prefix = 0;
        unordered_map<int, int> prefix_cnt;
        prefix_cnt[0] = 1;
        for (const auto &x: nums) {
            prefix += x;
            if (prefix_cnt[prefix - k]) {
                result += prefix_cnt[prefix - k];
            }
            ++prefix_cnt[prefix];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0560_H
