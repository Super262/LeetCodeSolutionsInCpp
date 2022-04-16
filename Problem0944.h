//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0944_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0944_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 检查每列是否为递增的
public:
    int minDeletionSize(const vector<string> &strs) {
        int ans = 0;
        const auto n = (int) strs[0].size();
        for (int j = 0; j < n; ++j) {
            bool is_sorted = true;
            for (int i = 1; i < (int) strs.size(); ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    is_sorted = false;
                    break;
                }
            }
            if (!is_sorted) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0944_H
