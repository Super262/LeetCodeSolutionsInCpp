//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0120_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0120_H

#include <vector>

using namespace std;

class Problem0120 {
public:
    int minimumTotal(const vector<vector<int>> &triangle) {
        vector<vector<int>> dp(2, vector<int>(triangle.size(), 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < (int) triangle.size(); ++i) {
            dp[i % 2][0] = triangle[i][0] + dp[(i - 1) % 2][0];
            for (int j = 1; j < i; ++j) {
                dp[i % 2][j] = triangle[i][j] + min(dp[(i - 1) % 2][j - 1], dp[(i - 1) % 2][j]);
            }
            dp[i % 2][i] = triangle[i][i] + dp[(i - 1) % 2][i - 1];
        }
        int result = 0x3f3f3f3f;
        for (int i = 0; i < (int) triangle.size(); ++i) {
            result = min(result, dp[(triangle.size() - 1) % 2][i]);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0120_H
