//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0947_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0947_H

#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
    // 每个石头看做一个点，将在同一行或一列的石头之间连边，这样可以形成若干个连通块；最终答案为每个连通块的大小减去 1 后的求和
    // 重要结论：在同一个连通块内，总存在一种方法，可以将其内部 move 到只剩下一块石头
public:
    int removeStones(vector<vector<int>> &stones) {
        const auto n = (int) stones.size();
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        unordered_map<int, vector<int>> row_s;  // 记录在同一行的石子
        unordered_map<int, vector<int>> col_s;  // 记录在同一列的石子
        for (int i = 0; i < n; ++i) {
            row_s[stones[i][0]].emplace_back(i);
            col_s[stones[i][1]].emplace_back(i);
        }
        for (const auto &item: row_s) {
            auto i = item.second[0];
            for (const auto &x: item.second) {
                mergeSets(i, x, parent, set_size);
            }
        }
        for (const auto &item: col_s) {
            auto i = item.second[0];
            for (const auto &x: item.second) {
                mergeSets(i, x, parent, set_size);
            }
        }
        bool existed[n];
        int cnt = 0;  // 统计连通块的个数
        memset(existed, 0, sizeof existed);
        for (int i = 0; i < n; ++i) {
            auto pi = findRoot(i, parent);
            if (existed[pi]) {
                continue;
            }
            existed[pi] = true;
            ++cnt;
        }
        return n - cnt;
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }

    void mergeSets(int a, int b, int parent[], int set_size[]) {
        auto pa = findRoot(a, parent);
        auto pb = findRoot(b, parent);
        if (pa == pb) {
            return;
        }
        // 将较小的集合并入较大的集合
        if (set_size[pa] < set_size[pb]) {
            parent[pa] = pb;
            set_size[pb] += set_size[pa];
        } else {
            parent[pb] = pa;
            set_size[pa] += set_size[pb];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0947_H
