//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0547_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0547_H

#include <vector>

using namespace std;

class Solution {
    // 并查集的应用，若a、b相连且a、b不在同个集合，我们合并a、b，省份数减1
public:
    int findCircleNum(const vector<vector<int>> &isConnected) {
        const auto n = (int) isConnected.size();
        int parent[n + 1];
        int sets_size[n + 1];
        for (int v = 1; v <= n; ++v) {
            parent[v] = v;
            sets_size[v] = 1;
        }
        auto cnt = n;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!isConnected[i - 1][j - 1]) {
                    continue;
                }
                auto pi = findRoot(i, parent);
                auto pj = findRoot(j, parent);
                if (pi == pj) {
                    continue;
                }
                mergeSets(pi, pj, parent, sets_size);
                --cnt;
            }
        }
        return cnt;
    }

private:
    int findRoot(int x, int parent[]) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (parent[x] != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int a, int b, int parent[], int sets_size[]) {
        if (a == b) {
            return -1;
        }
        if (sets_size[a] > sets_size[b]) {
            parent[b] = a;
            sets_size[a] += sets_size[b];
            return a;
        }
        parent[a] = b;
        sets_size[b] += sets_size[a];
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0547_H
