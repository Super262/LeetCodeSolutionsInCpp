//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0462_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0462_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    // 转化为货仓选址问题
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (auto &x: nums) {
            res += abs(x - nums[nums.size() / 2]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0462_H
