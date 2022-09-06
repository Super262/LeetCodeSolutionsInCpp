//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0118_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0118_H

#include <vector>

using namespace std;

class Problem0118 {
    // 经典DP
public:
    vector<vector<int>> generate(const int num_rows) {
        vector<vector<int>> ans;
        ans.reserve(num_rows);
        for (int i = 0; i < num_rows; ++i) {
            ans.emplace_back(vector<int>(i + 1, 0));
            ans[i][0] = 1;
            ans[i][ans[i].size() - 1] = 1;
        }
        for (int i = 2; i < num_rows; ++i) {
            for (int j = 1; j < (int) ans[i].size() - 1; ++j) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0118_H
