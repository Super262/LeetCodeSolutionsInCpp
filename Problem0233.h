//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0233_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0233_H

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOne(const int &n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> digits;
        auto t = n;
        while (t > 0) {
            digits.emplace_back(t % 10);
            t /= 10;
        }
        reverse(digits.begin(), digits.end());
        int result = 0;
        int left_num = 0;
        auto right_base = (int) pow(10, digits.size() - 1);
        for (const auto &x: digits) {
            auto right_num = n % right_base;
            if (x == 1) {
                result += left_num * right_base + right_num + 1;
            } else if (x == 0) {
                result += left_num * right_base;
            } else {
                result += (left_num + 1) * right_base;
            }
            left_num = left_num * 10 + x;
            right_base /= 10;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0233_H
