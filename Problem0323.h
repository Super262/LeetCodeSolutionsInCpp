
//
// Created by Fengwei Zhang on 5/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0323_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0323_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int countComponents(int n, const vector<vector<int>> &edges) {
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        int ans = n;
        for (const auto &e: edges) {
            auto pa = findRoot(e[0], parent);
            auto pb = findRoot(e[1], parent);
            if (pa == pb) {
                continue;
            }
            mergeSets(pa, pb, parent, set_size);
            --ans;
        }
        return ans;
    }

private:
    int findRoot(int x, int parent[]) {
        auto root = x;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (x != root) {
            auto p = parent[x];
            parent[x] = root;
            x = p;
        }
        return root;
    }

    int mergeSets(int pa, int pb, int parent[], int set_size[]) {
        if (pa == pb) {
            return -1;
        }
        if (set_size[pa] > set_size[pb]) {
            set_size[pa] += set_size[pb];
            parent[pb] = pa;
            return pa;
        }
        set_size[pb] += set_size[pa];
        parent[pa] = pb;
        return pb;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0323_H
