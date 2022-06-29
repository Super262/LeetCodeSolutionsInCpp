//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0647_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0647_H

#include <string>

using namespace std;

class Solution {
    // 中心线枚举，检测回文串；我们从位置i向左、右同时扩展，检测长度为奇数的回文串或长度为偶数的回文串
public:
    int countSubstrings(const string &s) {
        int ans = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            for (auto l = i, r = i; l >= 0 && r < (int) s.size(); --l, ++r) {  // 奇数长度
                if (s[l] != s[r]) {
                    break;
                }
                ++ans;
            }
            for (auto l = i, r = i + 1; l >= 0 && r < (int) s.size(); --l, ++r) {  // 偶数长度
                if (s[l] != s[r]) {
                    break;
                }
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0647_H
