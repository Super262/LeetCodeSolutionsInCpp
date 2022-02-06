//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0172_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0172_H

class Solution {
    // 经典算法，直接背诵
    // https://www.acwing.com/solution/content/19308/
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0172_H
