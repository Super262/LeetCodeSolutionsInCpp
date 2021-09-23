//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0012_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0012_H

#include <iostream>
#include <string>

using namespace std;

class Problem0012 {
private:
    string intToRoman(int num) {
        const int bases[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;
        while (num > 0) {
            for (int i = 0; i < 13; ++i) {
                if (num / bases[i] == 0) {
                    continue;
                }
                const int factor = num / bases[i];
                for (int j = 0; j < factor; ++j) {
                    result += symbols[i];
                    num -= bases[i];
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0012_H
