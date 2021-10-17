//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0166_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0166_H

#include <string>

using namespace std;

class Problem0166 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 模拟整数除法；哈希表判重
        long long x = numerator;  // 防止溢出（-2^31 / -1 会发生溢出）
        long long y = denominator;
        if (x % y == 0) {
            return to_string(x / y);
        }
        unordered_map<int, int> segIdx;
        string result;
        if ((x < 0) ^ (y < 0)) {  // 经典操作，要牢记
            result.push_back('-');
        }
        x = abs(x);
        y = abs(y);
        result += to_string(x / y);
        result.push_back('.');
        x %= y;
        while (x) {
            segIdx[(int) x] = (int) result.size();
            x *= 10;
            result.push_back((char) ('0' + x / y));
            x %= y;
            if (segIdx.count(x)) {
                result = result.substr(0, segIdx[(int) x]) + '(' + result.substr(segIdx[(int) x]) + ')';
                break;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0166_H
