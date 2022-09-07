//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1042_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1042_H

#include <vector>

using namespace std;

class Problem1042 {
    // 每个点最多有3条边和其它点相连，因为我们有4种颜色可选，我们可以对每个点任意染色
public:
    vector<int> gardenNoAdj(int n, const vector<vector<int>> &paths) {
        vector<int> graph[n];
        for (const auto &p: paths) {  // 建图，顶点从0开始编号
            auto a = p[0] - 1;
            auto b = p[1] - 1;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        vector<int> color(n, 0);  // color[i]：点i的颜色，初始时为0，表示无色
        bool used[5];  // used[c]：颜色c是否被使用
        for (int u = 0; u < n; ++u) {
            memset(used, 0, sizeof used);
            for (const auto &v: graph[u]) {  // 记录邻点的颜色
                used[color[v]] = true;
            }
            for (int c = 1; c <= 4; ++c) {  // 跳过邻点的颜色
                if (used[c]) {
                    continue;
                }
                used[c] = true;
                color[u] = c;
                break;
            }
        }
        return color;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1042_H
