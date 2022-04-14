//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0924_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0924_H

#include <vector>

using namespace std;

class Solution {
    // 若杀毒1个点，可使得部分点免于被感染，这个点应是它所在的连通块中唯一被感染的点
    // 因此，我们应找到满足条件的连通块，选择最大的一个
public:
    int minMalwareSpread(const vector<vector<int>> &graph, const vector<int> &initial) {
        const auto n = (int) graph.size();
        int parent[n];
        int c_size[n];
        int infected_cnt[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            c_size[i] = 1;
            infected_cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {  // 构建连通块
            for (int j = i + 1; j < n; ++j) {
                if (!graph[i][j]) {
                    continue;
                }
                auto pi = findRoot(i, parent);
                auto pj = findRoot(j, parent);
                if (pi == pj) {
                    continue;
                }
                parent[pj] = pi;
                c_size[pi] += c_size[pj];
            }
        }
        for (const auto &x: initial) {  // 统计每个连通块被感染的点
            infected_cnt[findRoot(x, parent)]++;
        }
        int r_size = -1;
        auto rp = n;
        for (const auto &x: initial) {
            auto px = findRoot(x, parent);
            if (r_size == -1) {  // 如果未找到满足题意的连通块，我们依然要保证索引最小
                rp = min(rp, x);
            }
            if (infected_cnt[px] != 1) {
                continue;
            }
            if (r_size < c_size[px]) {
                r_size = c_size[px];
                rp = x;
            } else if (r_size == c_size[px]) {
                rp = min(rp, x);
            }
        }
        return rp;
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0924_H
