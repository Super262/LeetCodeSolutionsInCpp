//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0268_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0268_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
    // 用sum{0...n}减去nums的和会得到未出现的数字
public:
    int missingNumber(const vector<int> &nums) {
        const auto n = (int) nums.size();
        auto all_sum = accumulate(nums.begin(), nums.end(), 0);
        return (n + 1) * n / 2 - all_sum;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0268_H
