//
// Created by Fengwei Zhang on 6/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0533_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0533_H

#include <vector>

using namespace std;

class Solution {
    // 设row_cnt[i]表示第i行'B'的个数，col_cnt[j]表示第j列'B'的个数
    // 题意解读：若pic[x][y]是孤独点，则row_cnt[x]=col_cnt[y]=target，并且对满足pic[k][y]='B'的任意行k，pic[k]=pic[x]（行相等）
    // 我们可以借助并查集，通过预处理，将相同的行合并到一个集合；查找孤独点时，直接通过并查集判断
public:
    int findBlackPixel(const vector<vector<char>> &pic, int target) {
        const auto m = (int) pic.size();
        const auto n = (int) pic[0].size();
        int parent[m];
        int set_size[m];
        for (int i = 0; i < m; ++i) {  // 并查集初始化
            parent[i] = i;
            set_size[i] = 1;
        }
        int row_cnt[m];
        int col_cnt[n];
        memset(row_cnt, 0, sizeof row_cnt);
        memset(col_cnt, 0, sizeof col_cnt);
        for (int i = 0; i < m; ++i) {  // 记录每行、每列的'B'的个数
            for (int j = 0; j < n; ++j) {
                if (pic[i][j] == 'W') {
                    continue;
                }
                ++row_cnt[i];
                ++col_cnt[j];
            }
        }
        for (int a = 1; a < m; ++a) {  // 预处理，合并相同行
            for (int b = 0; b < a; ++b) {
                bool flag = true;
                for (int j = 0; j < n; ++j) {
                    if (pic[a][j] != pic[b][j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    mergeSets(findRoot(a, parent), findRoot(b, parent), parent, set_size);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pic[i][j] == 'W' || row_cnt[i] != target || col_cnt[j] != target) {
                    continue;
                }
                int b_cnt = 0;
                int prev = -1;
                for (int k = 0; k < m; ++k) {
                    if (pic[k][j] == 'W') {
                        continue;
                    }
                    if (prev != -1 && findRoot(prev, parent) != findRoot(k, parent)) {
                        break;
                    }
                    ++b_cnt;
                    prev = k;
                }
                if (b_cnt == target) {
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    int findRoot(int x, int parent[]) {
        auto u = parent[x];
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0533_H
