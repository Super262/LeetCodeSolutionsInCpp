//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0007_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0007_H

#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return (int) result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0007_H
