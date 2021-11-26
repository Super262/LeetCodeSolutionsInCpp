//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0397_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0397_H

class Solution {
public:
    int integerReplacement(const long long &n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        }
        return 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0397_H
