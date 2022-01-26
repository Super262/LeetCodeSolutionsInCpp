//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0547_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0547_H

#include <vector>

using namespace std;

class Solution {
    // 没有按秩合并，并查集时间复杂度为O(logN)
public:
    int findCircleNum(const vector<vector<int>> &isConnected) {
        const auto n = (int) isConnected.size();
        int parent[n + 1];
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
        }
        auto cnt = n;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!isConnected[i - 1][j - 1]) {
                    continue;
                }
                auto pi = FindRoot(i, parent);
                auto pj = FindRoot(j, parent);
                if (pi == pj) {
                    continue;
                }
                parent[pj] = parent[pi];
                --cnt;
            }
        }
        return cnt;
    }

private:
    int FindRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = FindRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0547_H
