//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0118_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0118_H

#include <vector>

using namespace std;

class Problem0118 {
public:
    vector<vector<int>> generate(const int &numRows) {
        vector<vector<int>> dp;
        for (int i = 0; i < numRows; ++i) {
            dp.emplace_back(vector<int>(i + 1, 0));
            dp[i][0] = 1;
            dp[i][dp[i].size() - 1] = 1;
        }
        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < (int) dp[i].size() - 1; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0118_H
