//
// Created by Fengwei Zhang on 5/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0305_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0305_H

#include <vector>

using namespace std;

class Solution {
    // 并查集，参考AcWing 836
public:
    vector<int> numIslands2(int m, int n, const vector<vector<int>> &positions) {
        int parent[m * n];
        int set_size[m * n];
        bool existed[m * n];
        for (int i = 0; i < m * n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
            existed[i] = false;
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int islands = 0;
        vector<int> ans;
        ans.reserve(positions.size());
        for (const auto &p: positions) {
            auto a = p[0] * n + p[1];
            if (existed[a]) {
                ans.emplace_back(islands);
                continue;
            }
            existed[a] = true;
            ++islands;
            for (int j = 0; j < 4; ++j) {
                auto nx = p[0] + dx[j];
                auto ny = p[1] + dy[j];
                auto b = nx * n + ny;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || !existed[b]) {
                    continue;
                }
                auto pa = findRoot(a, parent);
                auto pb = findRoot(b, parent);
                if (pa == pb) {
                    continue;
                }
                --islands;
                mergeSets(pa, pb, parent, set_size);
            }
            ans.emplace_back(islands);
        }
        return ans;
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0305_H
