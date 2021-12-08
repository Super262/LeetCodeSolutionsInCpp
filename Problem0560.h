//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0560_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0560_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(const vector<int> &nums, int k) {
        int result = 0;
        int prefix = 0;
        unordered_map<int, int> pre_cnt;
        pre_cnt[0] = 1;
        for (const auto &x: nums) {
            prefix += x;
            if (pre_cnt[prefix - k]) {
                result += pre_cnt[prefix - k];
            }
            ++pre_cnt[prefix];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0560_H
