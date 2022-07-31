//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0773_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0773_H

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Problem0773 {
    // BFS，将每个图形看作是1个状态；我们从起点开始搜索，直至终点；每次变换，相当于前进一步
public:
    int slidingPuzzle(const vector<vector<int>> &board) {
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        string str;
        str.reserve(m * n);
        for (const auto &b: board) {  // 转化二维矩阵为字符串（行优先）
            for (const auto &x: b) {
                str += (char) ('0' + x);
            }
        }
        const string target = "123450";
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        unordered_map<string, int> dist;
        queue<string> q;
        q.emplace(str);
        dist[str] = 0;
        while (!q.empty()) {
            auto rs = q.front();
            q.pop();
            auto rd = dist[rs];
            if (rs == target) {
                return rd;
            }
            auto j = (int) rs.find_first_of('0');
            auto x = j / n;
            auto y = j % n;
            for (int i = 0; i < 4; ++i) {
                auto nx = x + dx[i];
                auto ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                auto nj = nx * n + ny;
                swap(rs[j], rs[nj]);
                if (!dist.count(rs)) {
                    dist[rs] = rd + 1;
                    q.emplace(rs);
                }
                swap(rs[j], rs[nj]);
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0773_H
