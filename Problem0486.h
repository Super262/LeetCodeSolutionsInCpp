//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0486_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0486_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/392/
    // 区间动态规划解决博弈论问题：f[i][j]表示先手玩家与后手玩家的得分差距的最大值
public:
    bool PredictTheWinner(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int f[n][n];
        memset(f, -0x3f, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = nums[i];
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                f[i][j] = max(f[i][j], max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]));
            }
        }
        return f[0][n - 1] >= 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0486_H
