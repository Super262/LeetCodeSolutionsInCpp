//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0504_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0504_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 将10进制数num模7，得到x，再设置num=num/7
    // 不断重复上述操作，将x加入答案，直到num为0
    // 最后，添加正负号、翻转答案
public:
    string convertToBase7(int num) {
        if (!num) {
            return "0";
        }
        auto is_neg = num < 0;
        num = abs(num);
        string res;
        while (num) {
            res += (char) ('0' + num % 7);
            num /= 7;
        }
        if (is_neg) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0504_H
