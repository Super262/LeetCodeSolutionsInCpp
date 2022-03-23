//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0062_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0062_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        for (int i = 0; i < n; ++i) {
            f[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            f[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0062_H
