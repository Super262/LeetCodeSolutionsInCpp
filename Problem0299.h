//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0299_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0299_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 直接遍历，哈希表统计
    // 若g中有t个字符在s中出现、有x个位置i满足g[i]=s[i]，y=s-x
public:
    string getHint(const string &s, const string &g) {
        int s_freq[10];
        memset(s_freq, 0, sizeof s_freq);
        for (auto ch: s) {
            ++s_freq[ch - '0'];
        }
        int t = 0;
        int x = 0;
        // 注意：以下2次统计一定要分开进行
        for (const auto &ch: g) {
            if (s_freq[ch - '0']) {
                ++t;
                --s_freq[ch - '0'];
            }
        }
        for (int i = 0; i < (int) g.size(); ++i) {
            if (g[i] == s[i]) {
                ++x;
            }
        }
        return to_string(x) + "A" + to_string(t - x) + "B";
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0299_H
