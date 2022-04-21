//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1001_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1001_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // 哈希表存储：行、列、2条对角线上的灯泡坐标
public:
    vector<int> gridIllumination(const int n, const vector<vector<int>> &lamps, const vector<vector<int>> &queries) {
        unordered_map<int, unordered_set<int>> col_lamps;  // 列的灯
        unordered_map<int, unordered_set<int>> row_lamps;  // 行的灯
        unordered_map<int, unordered_set<int>> dg_lamps;  // 对角线：b = y - x
        unordered_map<int, unordered_set<int>> rdg_lamps;  // 对角线：b = y + x
        for (const auto &l: lamps) {  // 记录所有灯
            auto x = l[0];
            auto y = l[1];
            col_lamps[y].insert(x);
            row_lamps[x].insert(y);
            dg_lamps[y - x].insert(x);
            rdg_lamps[y + x].insert(x);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < (int) queries.size(); ++i) {
            auto x = queries[i][0];
            auto y = queries[i][1];
            if (!col_lamps[y].empty() || !row_lamps[x].empty() || !dg_lamps[y - x].empty() ||
                !rdg_lamps[x + y].empty()) {  // 查询列、行、对角线
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
            // 删除3*3方格内的灯
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }
                    col_lamps[ny].erase(nx);
                    row_lamps[nx].erase(ny);
                    dg_lamps[ny - nx].erase(nx);
                    rdg_lamps[nx + ny].erase(nx);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1001_H
