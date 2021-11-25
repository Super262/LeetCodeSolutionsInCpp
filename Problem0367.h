//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0367_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0367_H

class Solution {
public:
    bool isPerfectSquare(const int &num) {
        int l = 0;
        int r = num;
        while (l < r) {
            auto mid = (int) (l + ((long long) r - l + 1) / 2);
            if (mid <= num / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l * l == num;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0367_H
