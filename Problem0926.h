//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0926_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0926_H

#include <string>

using namespace std;

class Solution {
    // 枚举分界点，将字符串划分为2部分，统计前半部1的个数x、后半部0的个数y，返回x+y；统计使用前缀和实现
public:
    int minFlipsMonoIncr(const string &s) {
        const auto n = (int) s.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
        }
        int ans = n;
        for (int i = 0; i <= n; ++i) {  // i表示前半段（全为零的部分）的长度
            auto x = prefix[i] - prefix[0];
            auto y = (n - i) - (prefix[n] - prefix[i]);
            ans = min(ans, x + y);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0926_H
