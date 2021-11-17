//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0312_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0312_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxCoins(const vector<int> &nums) {
        // 背诵代码！
        const int n = (int) nums.size();
        int temp[n + 2];
        temp[0] = 1;
        temp[n + 1] = 1;
        for (int i = 1; i <= n; ++i) {  // 拷贝原数据，开头和结尾补充1
            temp[i] = nums[i - 1];
        }
        // 注意这里的方程：dp[st][ed]表示打碎ballons[st + 1 : ed - 1]的最大价值！
        int dp[n + 2][n + 2];
        memset(dp, 0, sizeof dp);
        for (int len = 3; len <= n + 2; ++len) {
            for (int st = 0; st + len - 1 < n + 2; ++st) {
                const auto ed = st + len - 1;
                for (int mid = st + 1; mid < ed; ++mid) {
                    dp[st][ed] = max(dp[st][ed], temp[st] * temp[mid] * temp[ed] + dp[st][mid] + dp[mid][ed]);
                }
            }
        }

        return dp[0][n + 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0312_H
