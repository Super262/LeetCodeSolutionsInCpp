//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0397_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0397_H

#include <unordered_map>

using namespace std;

class Solution {
    // 记忆化搜索
public:
    int integerReplacement(int n) {
        unordered_map<long long, int> memo;
        return dfs(n, memo);
    }

private:
    int dfs(const long long &n, unordered_map<long long, int> &memo) {
        if (n == 1) {
            return 0;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        if (n % 2) {
            auto t = 1 + min(dfs(n + 1, memo), dfs(n - 1, memo));
            return memo[n] = t;
        }
        auto t = 1 + dfs(n / 2, memo);
        memo[n] = t;
        return t;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0397_H
