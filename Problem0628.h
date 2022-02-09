//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0628_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0628_H

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    // 经典算法，必须掌握：根据结果集反推原数组
    // https://www.acwing.com/solution/content/481/
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const auto n = (int) nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0628_H
