//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0330_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0330_H

#include <vector>

using namespace std;

class Solution {
    // 贪心算法：https://www.acwing.com/solution/content/4966/
public:
    int minPatches(const vector<int> &nums, const int &n) {
        long long miss = 1;  // 初始缺失的数字是1
        int res = 0;
        int idx = 0;
        while (miss <= n) {
            if (idx < nums.size() && nums[idx] <= miss) {
                miss += nums[idx];  // 扩充区间为[0, miss + nums[idx])
                ++idx;
            } else {
                miss *= 2;  // 直接添加miss
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0330_H