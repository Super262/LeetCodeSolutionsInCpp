//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0552_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0552_H

#include <cstring>

using namespace std;

class Solution {
    // f[i][a][l]：长度为i的序列中包含a个A、结尾有l个连续的L；从前向后枚举，由f[i]推导f[i+1]
public:
    int checkRecord(int n) {
        const int M = 1000000007;
        int f[n + 1][2][3];
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    if (!j) {  // 在结尾加入A
                        f[i + 1][j + 1][0] = (int) (((long long) f[i + 1][j + 1][0] + f[i][j][k]) % M);
                    }
                    if (k + 1 <= 2) {  // 在结尾加入L
                        f[i + 1][j][k + 1] = (int) (((long long) f[i + 1][j][k + 1] + f[i][j][k]) % M);
                    }
                    f[i + 1][j][0] = (int) (((long long) f[i + 1][j][0] + f[i][j][k]) % M);  // 在结尾加入P
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans = (int) (((long long) ans + f[n][j][k]) % M);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0552_H
