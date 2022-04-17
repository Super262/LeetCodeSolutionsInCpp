//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0960_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0960_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 仿照最长上升子序列问题，定义f[i]：每行字符串以第i列结尾时，在[0:i-1]列中删去的列的数量
public:
    int minDeletionSize(const vector<string> &strs) {
        const auto n = (int) strs[0].size();
        int f[n];
        auto ans = n;
        for (int i = 0; i < n; ++i) {
            f[i] = i;  // 初始值：将[0:i-1]全部删去
            for (int j = 0; j < i; ++j) {  // 向前寻找f[j]（j < i）
                bool is_less = true;
                for (const auto &s: strs) {
                    if (s[j] > s[i]) {
                        is_less = false;
                        break;
                    }
                }
                if (is_less) {
                    f[i] = min(f[i], f[j] + i - j - 1);
                }
            }
            ans = min(ans, f[i] + n - 1 - i);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0960_H
