//
// Created by Fengwei Zhang on 9/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0043_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0043_H

#include <iostream>
#include <string>

using namespace std;

class Problem0043 {
private:
    string intMulStr(string num, const unsigned long long digit) {
        string result;
        unsigned long long t = 0;
        unsigned long long i = 0;
        reverse(num.begin(), num.end());
        while (i < num.size() || t != 0) {
            if (i < num.size()) {
                t += digit * (num[i] - '0');
                ++i;
            }
            result.push_back('0' + t % 10);
            t /= 10;
        }
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string strPlusStr(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        unsigned long long t = 0;
        for (unsigned long long i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                t += a[i] - '0';
            }
            if (i < b.size()) {
                t += b[i] - '0';
            }
            result.push_back('0' + t % 10);
            t /= 10;
        }
        while (t > 0) {
            result.push_back('0' + t % 10);
            t /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string multiply(string num1, string num2) {
        string result = "0";
        reverse(num2.begin(), num2.end());
        unsigned long long exp = 1;
        for (unsigned long long i = 0; i < num2.size(); ++i) {
            string highPart = intMulStr(num1, (num2[i] - '0'));
            for (unsigned long long j = 1; j < exp; ++j) {
                highPart = intMulStr(highPart, 10);
            }
            result = strPlusStr(result, highPart);
            ++exp;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0043_H
