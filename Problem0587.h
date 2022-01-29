//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0587_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0587_H

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    // 计算几何，求凸包：https://www.acwing.com/solution/content/7451/
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        const auto n = (int) trees.size();
        set<vector<int>> answer;  // set支持vector为值，unordered_set不可以
        sort(trees.begin(), trees.end());  // 双关键字排序
        vector<vector<int>> stk;
        for (int i = 0; i < n; ++i) {
            while (stk.size() >= 2 && isOuter(stk[stk.size() - 2], stk.back(), trees[i])) {
                stk.pop_back();
            }
            stk.emplace_back(trees[i]);
        }
        for (const auto &p: stk) {
            answer.insert(p);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (stk.size() >= 2 && isOuter(stk[stk.size() - 2], stk.back(), trees[i])) {
                stk.pop_back();
            }
            stk.emplace_back(trees[i]);
        }
        for (int i = 1; i < stk.size() - 1; ++i) {
            answer.insert(stk[i]);
        }
        return {answer.begin(), answer.end()};
    }

private:
    bool isOuter(const vector<int> &a, const vector<int> &b, const vector<int> &c) {  // 利用ab与ac的差积判断ac是否在ab外侧
        auto x1 = b[0] - a[0];
        auto y1 = b[1] - a[1];
        auto x2 = c[0] - a[0];
        auto y2 = c[1] - a[1];
        return x1 * y2 - x2 * y1 < 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0587_H
