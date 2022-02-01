//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0054_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0054_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>> &matrix) {
        vector<int> result;
        const int n = (int) matrix.size();
        if (n == 0) {
            return result;
        }
        const int m = (int) matrix[0].size();
        bool visited[n][m];
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        memset(visited, 0, sizeof visited);
        for (int x = 0, y = 0, d = 0, i = 0; i < n * m; ++i) {
            result.emplace_back(matrix[x][y]);
            visited[x][y] = true;
            auto nx = x + dx[d];
            auto ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            x = nx;
            y = ny;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0054_H
