//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1035_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1035_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1035 {
    // 可以证明，此问题等价于最长公共子序列问题
public:
    int maxUncrossedLines(const vector<int> &nums1, const vector<int> &nums2) {
        const auto m = (int) nums1.size();
        const auto n = (int) nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        }
        return f[n][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1035_H
