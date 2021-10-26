//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0059_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0059_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem0059 {
public:
    vector<vector<int>> generateMatrix(const int &n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        bool visited[n][n];
        memset(visited, 0, sizeof visited);
        for (int x = 0, y = 0, d = 0, k = 1; k <= n * n; ++k) {
            result[x][y] = k;
            visited[x][y] = true;
            auto nx = x + dx[d];
            auto ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0059_H
