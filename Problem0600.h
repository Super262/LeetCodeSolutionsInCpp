//
// Created by Fengwei Zhang on 2/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0600_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0600_H

#include <algorithm>

using namespace std;

class Solution {
    // 数位DP；先预处理长度为i的二进制串中，以0作为最高位且符合条件的二进制串的个数f[i]=f[i-1]+f[i-2]
    // last_one表示上位是否为1，若n的当前位为1，直接累加f[i+1]；若n的当前位不为1，跳过；最后，n也是合法答案
    // https://www.acwing.com/solution/content/467/
public:
    int findIntegers(int n) {
        int f[31];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i < 31; ++i) {  // 预处理
            f[i] = f[i - 1] + f[i - 2];
        }
        bool last_one = false;
        int ans = 0;
        for (int i = 29; i >= 0; --i) {
            if ((n >> i) & 1) {
                ans += f[i + 1];
                if (last_one) {
                    return ans;
                }
                last_one = true;
            } else {
                last_one = false;
            }
        }
        return ans + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0600_H
