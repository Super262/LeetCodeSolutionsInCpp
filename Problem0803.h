//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0803_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0803_H

#include <vector>
#include <queue>

using namespace std;

class Problem0803 {
    // 并查集；正向解决，每次都需要迭代，会导致超时；我们逆向思考：先将所有被击中的砖块去掉，合并剩余砖块，
    // 再将被击中的砖块逆序加回，答案就是差值；使用并查集来代表每组相连的砖块，编号为s=m*n的集合表示和顶部相连的砖块
    // 初始化：拷贝grid到temp，设置被击中的位置为0，set_size[s]=0；将第0行砖块和s集合合并；将第0列砖块(i,0)和位置(i-1,0)的砖块合并
    // 从上至下、从左至右遍历，将当前砖块和左侧、上侧砖块合并；然后，逆序遍历hits数组，加入砖块、四周合并；若是第0行，将当前砖块和s合并
    // 因此，第i次hit后的答案就是 max(cur_cnt - pre_cnt - 1, 0)；别忘记最后的减1，要减去被击中的砖块，它不包括在下落的砖块中
public:
    vector<int> hitBricks(const vector<vector<int>> &grid, vector<vector<int>> &hits) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        const int s = m * n;
        int parent[s + 1];
        int sets_size[s + 1];
        for (int i = 0; i <= s; ++i) {
            parent[i] = i;
            sets_size[i] = 1;
        }
        sets_size[s] = 0;
        vector<vector<int>> temp(grid);
        for (const auto &x: hits) {
            temp[x[0]][x[1]] = 0;
        }
        vector<int> ans(hits.size());
        for (int j = 0; j < n; ++j) {
            if (!temp[0][j]) {
                continue;
            }
            mergeSets(findRoot(j, parent), findRoot(s, parent), sets_size, parent);
        }
        for (int i = 1; i < m; ++i) {
            if (!temp[i][0]) {
                continue;
            }
            if (temp[i - 1][0]) {
                mergeSets(findRoot((i - 1) * n, parent), findRoot(i * n, parent), sets_size, parent);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!temp[i][j]) {
                    continue;
                }
                auto x = i * n + j;
                if (temp[i - 1][j]) {
                    mergeSets(findRoot((i - 1) * n + j, parent), findRoot(x, parent), sets_size, parent);
                }
                if (temp[i][j - 1]) {
                    mergeSets(findRoot(i * n + j - 1, parent), findRoot(x, parent), sets_size, parent);
                }
            }
        }
        for (auto i = (int) hits.size() - 1; i >= 0; --i) {
            auto r = hits[i][0];
            auto c = hits[i][1];
            if (!grid[r][c]) {
                ans[i] = 0;
                continue;
            }
            auto pre_cnt = sets_size[findRoot(s, parent)];
            auto x = r * n + c;
            for (int k = 0; k < 4; ++k) {
                auto nr = r + dx[k];
                auto nc = c + dy[k];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || !temp[nr][nc]) {
                    continue;
                }
                mergeSets(findRoot(x, parent), findRoot(nr * n + nc, parent), sets_size, parent);
            }
            if (!r) {
                mergeSets(findRoot(x, parent), findRoot(s, parent), sets_size, parent);
            }
            temp[r][c] = 1;
            auto cur_cnt = sets_size[findRoot(s, parent)];
            ans[i] = max(cur_cnt - pre_cnt - 1, 0);
        }
        return ans;
    }

private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    int findRoot(int x, int parent[]) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int pa, int pb, int sets_size[], int parent[]) {
        if (pa == pb) {
            return -1;
        }
        if (sets_size[pa] > sets_size[pb]) {
            sets_size[pa] += sets_size[pb];
            parent[pb] = pa;
            return pa;
        }
        sets_size[pb] += sets_size[pa];
        parent[pa] = pb;
        return pb;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0803_H
