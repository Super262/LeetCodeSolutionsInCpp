//
// Created by Fengwei Zhang on 5/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0370_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0370_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 差分数组
public:
    vector<int> getModifiedArray(int n, const vector<vector<int>> &updates) {
        int diff[n + 2];
        memset(diff, 0, sizeof diff);
        for (const auto &e: updates) {
            diff[e[1] + 2] -= e[2];
            diff[e[0] + 1] += e[2];
        }
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i - 1];
        }
        vector<int> ans(n);
        for (int i = 1; i <= n; ++i) {
            ans[i - 1] = diff[i];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0370_H
