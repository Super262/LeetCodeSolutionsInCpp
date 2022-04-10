//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0887_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0887_H

#include <cstring>

class Solution {
    // f[i][j]：j枚鸡蛋、向上移动i次（每次可移动多层），可检测到的最大高度；假设我们当前（第1次尝试）处在高度为x的位置，扔下鸡蛋
    // 若鸡蛋碎掉，答案小于x，我们可以通过 i - 1 次移动和 j - 1 个鸡蛋来找到答案
    // 若鸡蛋没碎，答案大于或等于x，我们可以使用 i − 1 次移动和 j 个鸡蛋，再继续向上检查
    // f[i][j] = (f[i - 1][j - 1] + 1) + f[i - 1][j]；返回最小的 m 满足，f[m][k] >= n
    // 这里，状态的第一维可以省略，更新时只需要倒序更新即可；时间复杂度为 O(KlogN)
    // https://www.acwing.com/solution/content/6461/
public:
    int superEggDrop(int k, int n) {
        int f[n + 1][k + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = f[i - 1][j - 1] + 1 + f[i - 1][j];
                if (f[i][j] >= n) {
                    return i;
                }
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0887_H
