//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0008_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0008_H

class Problem0008 {
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
        bool isNeg = false;
        if (s[k] == '-') {
            ++k;
            isNeg = true;
        } else if (s[k] == '+') {
            ++k;
        }

        long long res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
            int x = s[k] - '0';
            // Detect overflow smartly.
            if (!isNeg && res > (INT_MAX - x) / 10) {
                return INT_MAX;
            }
            if (isNeg && -res < (INT_MIN + x) / 10) {
                return INT_MIN;
            }
            res = res * 10 + x;
            ++k;
        }

        if (isNeg) {
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
