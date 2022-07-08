//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0696_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0696_H

#include <string>

using namespace std;

class Solution {
    // 我们可以将字符串s分成多个组，每组由相同字符组成；例如，s="110001111000000"，每组长度为[2,3,4,6]
    // 分组后，我们可以计算出相邻两组长度的最小值，得到[2,3,4]；易知，答案即为2+3+4=7（例如，"0011"包含2个满足题意的子串）
    // 我们无须使用哈希表统计每组的长度，只需边遍历、边累计
public:
    int countBinarySubstrings(const string &s) {
        int ans = 0;
        int prev = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto j = i + 1;
            while (j < (int) s.size() && s[j] == s[i]) {
                ++j;
            }
            auto cur = j - i;
            ans += min(prev, cur);
            prev = cur;
            i = j - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0696_H
