//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0568_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0568_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典动态规划，f[i][j]表示在第i周、从城市j出发，在第i～m-1周、城市0～n-1间最多可享受的休假天数
    // f[i][j]初始值为days[j][i]+f[i+1][j]，f[i][j]=max({days[k][i]+f[i+1][k]})，城市j、k间存在航班
public:
    int maxVacationDays(const vector<vector<int>> &flights, const vector<vector<int>> &days) {
        const auto m = (int) days[0].size();
        const auto n = (int) flights.size();
        int f[m + 1][n];
        memset(f, 0, sizeof f);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = days[j][i] + f[i + 1][j];  // 第i周在城市j，第i+1周从城市j出发
                for (int k = 0; k < n; ++k) {
                    if (!flights[j][k]) {
                        continue;
                    }
                    f[i][j] = max(f[i][j], days[k][i] + f[i + 1][k]);  // 第i周在城市k，第i+1周从城市k出发
                }
            }
        }
        return f[0][0];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0568_H
