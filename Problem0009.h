//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0009_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0009_H

class Problem0009 {
public:
    bool isPalindrome(const int x) {
        if (x < 0) {
            return false;
        }
        unsigned long long reversed = 0;  // 避免溢出
        auto temp = x;
        while (temp) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        return reversed == x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0009_H
