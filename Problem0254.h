//
// Created by Fengwei Zhang on 5/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0254_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0254_H

#include <vector>

using namespace std;

class Solution {
    // DFS，注意细节
public:
    vector<vector<int>> getFactors(int n) {
        if (n == 1) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(n, cur, ans);
        return ans;
    }

private:
    void dfs(int n, vector<int> &cur, vector<vector<int>> &ans) {  // 尝试将n分解为至少2个因子
        if (n == 1) {
            return;
        }
        for (int f = cur.empty() ? 2 : cur.back(); f <= n / f; ++f) {  // 当前因子不小于上个因子，不多于sqrt(n)
            if (n % f) {
                continue;
            }
            cur.emplace_back(f);
            dfs(n / f, cur, ans);  // 尝试将(n/f)也分解为至少2个因子
            cur.emplace_back(n / f);  // 保存序列{a...f,(n/f)}
            ans.emplace_back(cur);
            cur.pop_back();
            cur.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0254_H
