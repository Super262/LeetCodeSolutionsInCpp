//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0678_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0678_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，必须掌握：DP + 优化
    // f[i][j]：前i个字符，能否组成剩余的j个左括号（下表从1开始），最后结果为f[n][0]
    // 假设满足 f[i][j] == true 的j的最小值为lower，最大值为upper，最后判断lower是否为0
    // https://www.acwing.com/solution/content/6126/
public:
    bool checkValidString(const string &s) {
        int lower = 0;
        int upper = 0;
        for (const auto &ch: s) {
            if (ch == '(') {
                ++upper;
                ++lower;
            } else if (ch == ')') {
                lower = max(lower - 1, 0);
                if (!upper) {
                    return false;
                }
                --upper;
            } else {
                lower = max(lower - 1, 0);
                ++upper;
            }
        }
        return lower == 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0678_H
