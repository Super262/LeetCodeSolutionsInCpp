//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0684_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0684_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法：并查集
public:
    vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
        const auto n = (int) edges.size();
        int parent[n + 1];
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (const auto &e: edges) {  // 为了尽可能输出靠后的结果，我们顺序遍历
            auto pa = findRoot(e[0], parent);
            auto pb = findRoot(e[1], parent);
            if (pa == pb) {
                return e;
            }
            parent[pb] = pa;
        }
        return {};
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0684_H
