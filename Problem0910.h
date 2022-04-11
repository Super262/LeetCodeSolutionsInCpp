//
// Created by Fengwei Zhang on 4/11/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0910_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0910_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心：由于我们只关心全局最大值、最小值，我们排序nums；从0开始，枚举分界点i
    // [0:i]段元素加|k|，[i+1,n)段元素减|k|，获得答案
public:
    int smallestRangeII(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for (int i = 0; i + 1 < (int) nums.size(); ++i) {
            auto maximal = max(nums[i] + k, nums.back() - k);
            auto minimal = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, maximal - minimal);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0910_H
