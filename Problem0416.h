//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0416_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0416_H

#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class Solution {
    // 转化为0/1背包问题：是否能装满容量为(m/2)的背包
    // f[i]：和为i的集合是否存在
public:
    bool canPartition(const vector<int> &nums) {
        const auto m = accumulate(nums.begin(), nums.end(), 0);
        if (m % 2) {  // 无法平分
            return false;
        }
        bool f[m + 1];
        memset(f, 0, sizeof f);
        f[0] = true;
        for (const auto &x: nums) {
            for (auto j = m; j >= x; --j) {
                f[j] |= f[j - x];
            }
        }
        return f[m / 2];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0416_H
