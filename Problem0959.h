//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0959_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0959_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 判断连通区域常用并查集；对于任意的正方形，它被两条对角线分成4个区域（上下左右，4个三角形，编号k为0、2、3、1）
    // 我们可以根据输入，建立这4个区域间的连通关系，确定最终的连通块的个数
    // 正方形格子的坐标是(i,j)，小三角形的编号是(i,j,k)
public:
    int regionsBySlashes(const vector<string> &grid) {
        const auto m = (int) grid.size();
        const auto n = (int) grid[0].size();
        int parent[m * n * 4];
        int set_size[m * n * 4];
        for (int i = 0; i < m * n * 4; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    // 相邻的三角形一定连通（如(i,j,0)和(i-1,j,2)），先行合并
                    auto ni = i + dx[k];
                    auto nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) {  // 越界
                        continue;
                    }
                    mergeSets(findRoot(realIdx(i, j, k, n), parent),
                              findRoot(realIdx(ni, nj, k ^ 2, n), parent),
                              parent,
                              set_size);
                }
                if (grid[i][j] != '/') {  //  "/"不存在，合并0、1，2、3
                    mergeSets(findRoot(realIdx(i, j, 0, n), parent),
                              findRoot(realIdx(i, j, 1, n), parent),
                              parent,
                              set_size);
                    mergeSets(findRoot(realIdx(i, j, 2, n), parent),
                              findRoot(realIdx(i, j, 3, n), parent),
                              parent,
                              set_size);
                }
                if (grid[i][j] != '\\') {  //  "\"不存在，合并0、3，1、2
                    mergeSets(findRoot(realIdx(i, j, 1, n), parent),
                              findRoot(realIdx(i, j, 2, n), parent),
                              parent,
                              set_size);
                    mergeSets(findRoot(realIdx(i, j, 0, n), parent),
                              findRoot(realIdx(i, j, 3, n), parent),
                              parent,
                              set_size);
                }
            }
        }
        bool existed[m * n * 4];
        int set_cnt = 0;  // 统计连通块的个数
        memset(existed, 0, sizeof existed);
        for (int i = 0; i < m * n * 4; ++i) {
            auto pi = findRoot(i, parent);
            if (existed[pi]) {
                continue;
            }
            existed[pi] = true;
            ++set_cnt;
        }
        return set_cnt;
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] < set_size[b]) {
            parent[a] = b;
            set_size[b] += set_size[a];
            return b;
        }
        parent[b] = a;
        set_size[a] += set_size[b];
        return a;
    }

    int realIdx(int i, int j, int k, int n) {
        return (i * n + j) * 4 + k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0959_H
