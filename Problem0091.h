//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0091_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0091_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // f[i]：s[0:i-1]部分的解码方式
public:
    int numDecodings(const string &s) {
        const auto n = (int) s.size();
        int f[n + 1];
        f[0] = 1;
        for (int len = 1; len <= n; ++len) {
            f[len] = 0;
            if (s[len - 1] >= '1' && s[len - 1] <= '9') {
                f[len] += f[len - 1];
            }
            if (len == 1) {
                continue;
            }
            auto num = (int) (s[len - 2] - '0') * 10 + (int) (s[len - 1] - '0');
            if (num < 10 || num > 26) {
                continue;
            }
            f[len] += f[len - 2];
        }
        return f[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0091_H
