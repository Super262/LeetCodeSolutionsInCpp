//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0526_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0526_H

#include <cstring>

class Solution {
    // 暴力搜索（DFS）所有的排列perm，保证perm中每项都满足题意
public:
    int countArrangement(int n) {
        bool used[n + 1];
        memset(used, 0, sizeof used);
        int ans = 0;
        dfs(1, n, used, ans);
        return ans;
    }

private:
    void dfs(int idx, int n, bool used[], int &ans) {
        if (idx >= n + 1) {
            ++ans;
            return;
        }
        for (int num = 1; num <= n; ++num) {
            if (used[num] || (num % idx && idx % num)) {
                continue;
            }
            used[num] = true;
            dfs(idx + 1, n, used, ans);
            used[num] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0526_H
