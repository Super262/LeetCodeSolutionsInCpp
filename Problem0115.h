//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0115_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0115_H

#include <string>
#include <cstring>

using namespace std;

class Problem0115 {
    // f[i][j]表示s[1,i]的子序列生成t[1,j]的方式数
    // 防溢出：最终答案不超过INT_MAX，但中间结果可能超过INT_MAX
public:
    int numDistinct(const string &s, const string &t) {
        const auto n = (int) s.size();
        const auto m = (int) t.size();
        unsigned long long f[2][m + 1]; // 滚动数组优化
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n; ++i) {
            f[i % 2][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i % 2][j] = f[(i - 1) % 2][j];
                if (s[i - 1] == t[j - 1]) {
                    f[i % 2][j] += f[(i - 1) % 2][j - 1];
                }
            }
        }
        return (int) f[n % 2][m];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0115_H
