//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0546_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0546_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // f[i][j][k]：将[i:j]清空，最后删除i，且最后删除k个盒子的所有方案（注意：本题最后被删掉的部分不一定是后缀）中的最大积分
    // g[i][j]为所有f[i][j][k]的最大值；转移时，我们定义2种情况：(1)单独删除boxes[i]；(2)boxes[i]与后边的同颜色的盒子合并删除
    // 对于情况(2)，f[i][j][k]=max(f[i][j][k],g[i+1][p-1]+f[p][j][k-1]-(k-1)^2+k^2)，其中boxes[i]==boxes[p]
    // 也就是说，我们找到了盒子boxes[p]，想要boxes[i]与它一起删除，则此时的删除操作可以分为两部分：首先，删除区间[i+1,p-1]，然后删除盒子i和区间[p,j]
    // https://www.acwing.com/solution/content/6168/
public:
    int removeBoxes(vector<int> &boxes) {
        const auto n = (int) boxes.size();
        int f[n][n][n + 1];
        int g[n][n];
        memset(f, -0x3f, sizeof f);
        memset(g, -0x3f, sizeof g);
        for (int i = 0; i < n; ++i) {  // 初始化
            f[i][i][1] = 1;
            f[i][i][0] = 0;
            g[i][i] = 1;
        }
        for (int i = 1; i < n; ++i) {  // 这个特殊初值会被用到
            g[i][i - 1] = 0;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                f[i][j][1] = 1 + g[i + 1][j];
                for (auto p = i + 1; p <= j; ++p) {
                    if (boxes[i] != boxes[p]) {
                        continue;
                    }
                    for (int k = 2; k <= length; ++k) {
                        f[i][j][k] = max(f[i][j][k], g[i + 1][p - 1] + f[p][j][k - 1] - (k - 1) * (k - 1) + k * k);
                    }
                }
                for (int k = 1; k <= length; ++k) {
                    g[i][j] = max(g[i][j], f[i][j][k]);
                }
            }
        }
        return g[0][n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0546_H
