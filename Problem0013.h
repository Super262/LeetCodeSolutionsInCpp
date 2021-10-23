//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0013_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0013_H

class Problem0013 {
public:
    int romanToInt(const string &s) {
        int ch2Num[256];
        ch2Num['I'] = 1;
        ch2Num['V'] = 5;
        ch2Num['X'] = 10;
        ch2Num['L'] = 50;
        ch2Num['C'] = 100;
        ch2Num['D'] = 500;
        ch2Num['M'] = 1000;
        ch2Num['N'] = 1001;  // 边界值

        int result = 0;
        char prev = 'N';
        for (auto ch: s) {
            if (ch2Num[ch] > ch2Num[prev]) {  // 出现逆序，遇到特殊字符组合：IV......CM
                result -= 2 * ch2Num[prev];
            }
            result += ch2Num[ch];
            prev = ch;
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0013_H
