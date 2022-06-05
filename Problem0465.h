
//
// Created by Fengwei Zhang on 6/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0465_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0465_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 用哈希表统计每人的余额balance，若借出x，余额加x；若借入x，余额减x
    // 抽取出每人的余额，构成money序列；DFS，枚举i，将序列money[0:i]的余额转入money[i+1]，记录最小操作次数
    // 剪枝：若当前步数steps大于或等于答案ans，停止搜索
public:
    int minTransfers(const vector<vector<int>> &trans) {
        unordered_map<int, int> balance;
        for (const auto &t: trans) {
            if (!balance.count(t[0])) {
                balance[t[0]] = 0;
            }
            if (!balance.count(t[1])) {
                balance[t[1]] = 0;
            }
            balance[t[0]] += t[2];
            balance[t[1]] -= t[2];
        }
        vector<int> money;
        money.reserve(balance.size());
        for (const auto &item: balance) {
            money.emplace_back(item.second);
        }
        int ans = INT_MAX;
        dfs(money, 0, 0, ans);
        return ans;
    }

private:
    void dfs(vector<int> &money, int st, int steps, int &ans) {
        if (steps >= ans) {
            return;
        }
        while (st < (int) money.size() && !money[st]) {
            ++st;
        }
        if (st == (int) money.size()) {
            ans = min(ans, steps);
            return;
        }
        for (auto i = st + 1; i < (int) money.size(); ++i) {
            money[i] += money[st];
            dfs(money, st + 1, steps + 1, ans);
            money[i] -= money[st];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0465_H
