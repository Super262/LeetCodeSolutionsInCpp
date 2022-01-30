//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0013_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0013_H

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(const string &s) {
        int ch_to_num[256];
        ch_to_num['I'] = 1;
        ch_to_num['V'] = 5;
        ch_to_num['X'] = 10;
        ch_to_num['L'] = 50;
        ch_to_num['C'] = 100;
        ch_to_num['D'] = 500;
        ch_to_num['M'] = 1000;
        ch_to_num['N'] = 1001;  // 边界值

        int result = 0;
        char prev = 'N';
        for (auto ch: s) {
            if (ch_to_num[ch] > ch_to_num[prev]) {  // 出现逆序，遇到特殊字符组合：IV......CM
                result -= 2 * ch_to_num[prev];
            }
            result += ch_to_num[ch];
            prev = ch;
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0013_H
