//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0263_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0263_H

class Solution {
    // 持续用2/3/5除n，直到n为零
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0263_H
