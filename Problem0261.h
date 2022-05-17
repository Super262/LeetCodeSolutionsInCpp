
//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0261_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0261_H

#include <vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, const vector<vector<int>> &edges) {
        if ((int) edges.size() != (n - 1)) {
            return false;
        }
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        for (const auto &e: edges) {
            auto pa = findRoot(e[0], parent);
            auto pb = findRoot(e[1], parent);
            auto r = mergeSets(pa, pb, parent, set_size);
            if (r == -1) {
                return false;
            }
        }
        return true;
    }

private:
    int findRoot(int x, int parent[]) {
        auto root = x;
        while (parent[root] != root) {
            root = parent[root];
        }
        while (x != root) {
            auto prev = parent[x];
            parent[x] = root;
            x = prev;
        }
        return root;
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] > set_size[b]) {
            parent[b] = a;
            set_size[a] += set_size[b];
            return a;
        }
        parent[a] = b;
        set_size[b] += set_size[a];
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0261_H
