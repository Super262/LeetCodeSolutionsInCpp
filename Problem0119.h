//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0119_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0119_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(const int &rowIndex) {
        vector<vector<int>> dp(2, vector<int>(rowIndex + 1, 1));
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[(i - 1) % 2][j - 1];
            }
        }
        return dp[rowIndex % 2];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0119_H
