//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0526_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0526_H

#include <cstring>

class Solution {
public:
    int countArrangement(int n) {
        bool used[n + 1];
        memset(used, 0, sizeof used);
        int result = 0;
        dfs(1, n, used, result);
        return result;
    }

private:
    void dfs(int idx, int n, bool used[], int &result) {
        if (idx >= n + 1) {
            ++result;
            return;
        }
        for (int num = 1; num <= n; ++num) {
            if (used[num] || (num % idx && idx % num)) {
                continue;
            }
            used[num] = true;
            dfs(idx + 1, n, used, result);
            used[num] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0526_H
