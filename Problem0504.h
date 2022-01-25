//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0504_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0504_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (!num) {
            return "0";
        }
        auto is_neg = num < 0;
        num = abs(num);
        string res;
        while (num) {
            res.push_back((char) ('0' + num % 7));
            num /= 7;
        }
        if (is_neg) {
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0504_H
