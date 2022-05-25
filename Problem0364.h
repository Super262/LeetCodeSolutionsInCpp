
//
// Created by Fengwei Zhang on 5/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0364_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0364_H

#include "nestedinteger.h"
#include <numeric>
#include <queue>

using namespace std;

class Solution {
    // BFS，层序遍历，获取每个数字的深度和全局最大深度
public:
    int depthSumInverse(const vector<NestedInteger> &nested_list) {
        vector<pair<int, int>> temp;
        queue<NestedInteger> q;
        int depth = 0;
        for (const auto &x: nested_list) {
            q.emplace(x);
        }
        while (!q.empty()) {
            ++depth;
            for (auto i = (int) q.size(); i > 0; --i) {
                auto t = q.front();
                q.pop();
                if (t.isInteger()) {
                    temp.emplace_back(depth, t.getInteger());
                    continue;
                }
                for (const auto &x: t.getList()) {
                    q.emplace(x);
                }
            }
        }
        int ans = 0;
        for (const auto &p: temp) {
            ans += (depth - p.first + 1) * p.second;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0364_H
