//
// Created by Fengwei Zhang on 9/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0231_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0231_H

class Problem0231 {
private:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0231_H
