//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0799_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0799_H

#include <algorithm>
#include <cstring>

using namespace std;

class Problem0799 {
    // 动态规划，f[r][c]表示(r,c)处杯子的香槟量；f[r][c]=(f[r-1][c-1]-1)/2+(f[r-1][c]-1)/2
    // 我们从第r=1行开始递推，初始时，f[0][0]=poured
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double f[query_row + 1][query_row + 1];
        memset(f, 0, sizeof f);
        f[0][0] = poured;
        for (int r = 1; r <= query_row; ++r) {
            if (f[r - 1][0] > 1) {
                f[r][0] += (f[r - 1][0] - 1) / 2.0;
            }
            for (int c = 1; c < r; ++c) {
                if (f[r - 1][c - 1] > 1) {
                    f[r][c] += (f[r - 1][c - 1] - 1) / 2.0;
                }
                if (f[r - 1][c] > 1) {
                    f[r][c] += (f[r - 1][c] - 1) / 2.0;
                }
            }
            if (f[r - 1][r - 1] > 1) {
                f[r][r] += (f[r - 1][r - 1] - 1) / 2.0;
            }
        }
        return min(1.0, f[query_row][query_glass]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0799_H
