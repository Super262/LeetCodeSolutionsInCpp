//
// Created by Fengwei Zhang on 10/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0087_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0087_H

#include <string>

using namespace std;

class Solution {
    // 区间DP，经典算法，直接背诵：https://www.acwing.com/solution/content/170/
    // f[i][j][k]：s1[i:i+k-1]和s2[j:j+k-1]是否匹配；设分界点为m（0<=m<k-1）
    // 两种匹配情况：s1[i:i+m]和s2[j:j+m]匹配，s1[i+m+1:i+k-1]和s2[j+m+1:j+k-1]匹配
    //             s1[i:i+m]和s2[j+m+1:j+k-1]匹配，s1[i+m+1:i+k-1]和s2[j:j+m]匹配
public:
    bool isScramble(const string &s1, const string &s2) {
        if (s1 == s2) {
            return true;
        }
        const int n = (int) s1.size();
        bool f[n][n][n + 1];
        memset(f, 0, sizeof f);
        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    if (k == 1) {
                        f[i][j][k] = s1[i] == s2[j];
                        continue;
                    }
                    for (int l = 1; l < k; ++l) {
                        if (f[i][j][l] && f[i + l][j + l][k - l]) {
                            f[i][j][k] = true;
                            break;
                        }
                        if (f[i][j + k - l][l] && f[i + l][j][k - l]) {
                            f[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[0][0][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0087_H
