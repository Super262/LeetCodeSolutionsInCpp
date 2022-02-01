//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0059_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0059_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    vector<vector<int>> generateMatrix(const int n) {
        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {1, 0, -1, 0};
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int x = 0, y = 0, d = 0, k = 1; k <= n * n; ++k) {
            result[x][y] = k;
            auto nx = x + dx[d];
            auto ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || result[nx][ny]) {
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
