//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0481_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0481_H

#include <string>

using namespace std;

class Solution {
    // 找规律，直接模拟
public:
    int magicalString(int n) {
        string s = "122";
        for (int i = 2, ch = 1; s.size() < n; ++i, ch = 3 - ch) {
            for (int j = 0; j < s[i] - '0'; ++j) {
                s.push_back((char) (ch + '0'));
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0481_H
