//
// Created by Fengwei Zhang on 5/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0339_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0339_H

#include <vector>
#include <queue>
#include "nestedinteger.h"

using namespace std;

class Solution {
    // BFS，类似层序遍历
public:
    int depthSum(const vector<NestedInteger> &nested_list) {
        int ans = 0;
        queue<NestedInteger> q;
        for (const auto &ni: nested_list) {
            q.emplace(ni);
        }
        int depth = 1;
        while (!q.empty()) {
            for (auto i = (int) q.size(); i > 0; --i) {
                auto ni = q.front();
                q.pop();
                if (ni.isInteger()) {
                    ans += ni.getInteger() * depth;
                    continue;
                }
                for (const auto &kni: ni.getList()) {
                    q.emplace(kni);
                }
            }
            ++depth;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0339_H
