//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0009_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0009_H

class Problem0009 {
private:
    bool isPalindrome(const int &x) {
        if (x < 0) {
            return false;
        }
        long long res = 0;  // To avoid overflow!
        auto temp = x;
        while (temp) {
            res = res * 10 + temp % 10;
            temp /= 10;
        }
        return res == x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0009_H
