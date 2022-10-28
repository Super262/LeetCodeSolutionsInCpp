//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0012_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0012_H

#include <iostream>
#include <string>

using namespace std;

class Problem0012 {
    // 从大到小试除因子
public:
    string intToRoman(int num) {
        const int K = 13;
        const int base[K] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[K] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for (int i = 0; i < K && num; ++i) {
            if (num / base[i] == 0) {
                continue;
            }
            auto f = num / base[i];
            for (int j = 0; j < f; ++j) {
                ans += symbol[i];
            }
            num -= base[i] * f;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0012_H
