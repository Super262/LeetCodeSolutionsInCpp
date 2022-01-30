//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0008_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0008_H

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(const string &s) {
        int k = 0;

        // Skip whitespaces.
        while (k < s.size() && s[k] == ' ') {
            ++k;
        }
        if (k == s.size()) {
            return 0;
        }

        // Check '-'
        bool is_neg = false;
        if (s[k] == '-') {
            ++k;
            is_neg = true;
        } else if (s[k] == '+') {
            ++k;
        }

        long long res = 0;
        while (k < s.size() && isdigit(s[k])) {
            int x = s[k] - '0';
            // Detect overflow smartly.
            if (!is_neg && res > (INT_MAX - x) / 10) {
                return INT_MAX;
            }
            if (is_neg && -res < (INT_MIN + x) / 10) {
                return INT_MIN;
            }
            res = res * 10 + x;
            ++k;
        }

        if (is_neg) {
            res = -res;
        }
        if (res < INT_MIN) {
            return INT_MIN;
        }
        if (res > INT_MAX) {
            return INT_MAX;
        }

        return (int) res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0008_H
