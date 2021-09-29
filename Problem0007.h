//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0007_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0007_H

class Problem0007 {
private:
    int reverse(const int x) {
        long long temp = x;
        bool isNeg = false;
        if (temp < 0) {
            isNeg = true;
            temp = -temp; // 若temp是int类型，这一步可能会溢出（x = INT_MIN时）
        }
        long long result = 0;
        while (temp > 0) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        if (isNeg) {
            result = -result;
        }
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return (int) result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0007_H
