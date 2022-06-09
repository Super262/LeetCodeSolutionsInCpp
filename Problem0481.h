//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0481_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0481_H

#include <string>

using namespace std;

class Solution {
    // 找规律，直接模拟：初始时s="122"，i=2（s[0:i-1]可以"描述"s[0:i]）
    // 我们根据s[i]为s添加新字符，并递增i，直到s长度超过n
public:
    int magicalString(int n) {
        string s = "122";
        for (int i = 2, ch = 1; (int) s.size() < n; ++i, ch = 3 - ch) {
            for (int j = 0; j < s[i] - '0'; ++j) {
                s += (char) (ch + '0');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0481_H
