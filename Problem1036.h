//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1036_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1036_H

#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // 离散化 + 广度优先搜索
    // 我们也可以借助离散化技巧将网格「压缩」成一个规模较小的但等价的新网格，并在新网格上进行常规的广度优先搜索
    // 以网格的每一行为例，可以发现，不同的行坐标只有：
    //      障碍所在的行，最多有n个；source和target所在的行，最多有2个；网格的上下边界（即-1和10^6），有2个
    // 因此，不同的行坐标最多只有n+4个，我们可以对行坐标进行离散化，具体的规则如下：
    //      我们将行坐标进行升序排序；将上边界离散化为-1，上边界是排序后的第0个行坐标；
    //      如果排序后的第i个行坐标与第(i-1)个行坐标相同，那么它们离散化后的值也相同；
    //      如果排序后的第i个行坐标与第(i-1)个行坐标相差1，那么它们离散化后的值也相差1；
    //      如果排序后的第i个行坐标与第(i-1)个行坐标相差超过2，那么它们离散化后的值也相差2。
    // 这样的正确性在于：在离散化前，如果两个行坐标本身相邻，那么在离散化之后它们也必须相邻；
    //              如果它们不相邻，可以把它们之间间隔的若干行直接"压缩"成一行，即行坐标相差2。
    // 对于列坐标的离散化方法也是如此。在离散化完成之后，新的网格的规模不会超过2*(n+4)*2*(n+4)，进行广度优先搜索需要的时间是可接受的。
public:
    bool isEscapePossible(const vector<vector<int>> &blocked, const vector<int> &src, const vector<int> &tar) {
        if (blocked.size() < 2) {  // 特殊情况
            return true;
        }

        // 初始化
        vector<int> rows;
        vector<int> columns;
        rows.reserve(blocked.size() + 2);
        columns.reserve(blocked.size() + 2);
        rows.emplace_back(src[0]);
        columns.emplace_back(src[1]);
        rows.emplace_back(tar[0]);
        columns.emplace_back(tar[1]);
        for (const auto &pos: blocked) {
            rows.emplace_back(pos[0]);
            columns.emplace_back(pos[1]);
        }

        // 保序离散化
        sort(rows.begin(), rows.end());
        sort(columns.begin(), columns.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        columns.erase(unique(columns.begin(), columns.end()), columns.end());

        // 记录行映射
        unordered_map<int, int> row_idx;
        int r_id = rows[0] == 0 ? 0 : 1;
        row_idx[rows[0]] = r_id;
        for (int i = 1; i < (int) rows.size(); ++i) {
            if (rows[i] == rows[i - 1] + 1) {
                ++r_id;
            } else {
                r_id += 2;
            }
            row_idx[rows[i]] = r_id;
        }
        if (rows.back() < BOUNDARY - 1) {  // 不要忘了这步：我们要扩展离散后的空间，使它和真实空间（10^6）相等
            ++r_id;
        }

        // 记录列映射
        unordered_map<int, int> column_idx;
        int c_id = columns[0] == 0 ? 0 : 1;
        column_idx[columns[0]] = c_id;
        for (int i = 1; i < (int) columns.size(); ++i) {
            if (columns[i] == columns[i - 1] + 1) {
                ++c_id;
            } else {
                c_id += 2;
            }
            column_idx[columns[i]] = c_id;
        }
        if (columns.back() < BOUNDARY - 1) {
            ++c_id;
        }

        // 建立新图
        int grid[r_id + 1][c_id + 1];
        memset(grid, 0, sizeof grid);
        for (const auto &pos: blocked) {
            grid[row_idx[pos[0]]][column_idx[pos[1]]] = 1;
        }
        const auto sx = row_idx[src[0]];
        const auto sy = column_idx[src[1]];
        const auto tx = row_idx[tar[0]];
        const auto ty = column_idx[tar[1]];

        // BFS
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        grid[sx][sy] = 1;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto x = u.first;
            auto y = u.second;
            if (x == tx && y == ty) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= r_id + 1 || ny >= c_id + 1 || grid[nx][ny]) {
                    continue;
                }
                q.emplace(nx, ny);
                grid[nx][ny] = 1;
            }
        }
        return false;
    }

private:
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};
    static const int BOUNDARY = 1e6;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1036_H
