//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0166_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0166_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 模拟整数除法，用哈希表判重，以确定循环节的起点和终点
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long x = numerator;  // 防止溢出（-2^31 / -1 会发生溢出）
        long long y = denominator;
        if (x % y == 0) {  // 无余数，直接返回整数
            return to_string(x / y);
        }
        unordered_map<int, int> remainder_idx;
        string ans;
        if ((x < 0) ^ (y < 0)) {  // x、y的正负性不同（经典操作，要牢记）
            ans.push_back('-');
        }
        x = abs(x);
        y = abs(y);
        ans += to_string(x / y);  // 保存整数和小数点
        ans.push_back('.');
        x %= y;
        while (x) {  // 模拟算数乘法
            remainder_idx[(int) x] = (int) ans.size();
            x *= 10;
            ans.push_back((char) ('0' + x / y));
            x %= y;
            if (remainder_idx.count((int) x)) {
                ans = ans.substr(0, remainder_idx[(int) x]) + '(' + ans.substr(remainder_idx[(int) x]) + ')';
                break;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0166_H
