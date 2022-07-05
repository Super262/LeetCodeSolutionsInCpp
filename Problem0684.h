//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0684_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0684_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 并查集，找到边(a,b)，满足a、b在同个集合
public:
    vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
        const auto n = (int) edges.size();
        int parent[n + 1];
        int set_size[n + 1];
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        for (const auto &e: edges) {  // 为了尽可能输出靠后的结果，我们顺序遍历
            auto pa = findRoot(e[0], parent);
            auto pb = findRoot(e[1], parent);
            if (pa == pb) {
                return e;
            }
            mergeSets(pa, pb, parent, set_size);
        }
        return {};
    }

private:
    int findRoot(int x, int parent[]) {
        auto u = x;
        while (parent[u] != u) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] > set_size[b]) {
            set_size[a] += set_size[b];
            parent[b] = a;
            return a;
        }
        set_size[b] += set_size[a];
        parent[a] = b;
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0684_H
