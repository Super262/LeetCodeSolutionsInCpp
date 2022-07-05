//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0678_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0678_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，必须掌握：DP + 优化；f[i][j]：前i个字符，能否组成剩余的j个左括号（i>=1）
    // 若s[i]='('，则f[i][j]=f[i-1][j-1]；若s[i]=')'，则f[i][j]=f[i-1][j+1]
    // 若s[i]='*'，f[i][j]=min(f[i-1][j],f[i-1][j+1],f[i-1][j-1])；初始时，f[0][0]=true，最终答案为f[n][0]
    // 我们发现这里有许多冗余计算，设满足f[i][j]=true的最小j为l、最大j为r，那么f[i][l:r]均为true；
    // 因此，我们只需要根据DP过程记录上、下界；假设满足f[i][j]=true的j的最小值为lower，最大值为upper，最后判断lower是否为0
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
