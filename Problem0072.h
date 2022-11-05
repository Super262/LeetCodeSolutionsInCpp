//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0072_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0072_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0072 {
    // f[i][j]：将长度为i的字符串a、长度为j的字符串b修正为相同的字符串修正为相同的字符串需要的最少操作次数
public:
    int minDistance(const string &a, const string &b) {
        if (a.empty()) {
            return (int) b.size();
        }
        if (b.empty()) {
            return (int) a.size();
        }
        const auto m = (int) a.size();
        const auto n = (int) b.size();
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof f);  // 初始化为无效值
        for (int i = 0; i <= n; ++i) {  // 特殊情况：a为空，b非空
            f[0][i] = i;
        }
        for (int i = 0; i <= m; ++i) {  // 特殊情况：a非空，b为空
            f[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);  // 可能无需操作
                }
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);  // 修改a或b的最后一个字符使它们匹配
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);  // 为匹配a[i]，在b的末尾插入新字符
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);  // 为匹配b[i]，在a的末尾插入新字符
            }
        }
        return f[m][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0072_H
