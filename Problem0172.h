//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0172_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0172_H

class Solution {
    // 直接背诵：设x = n!，若x尾部有k个"0"，说明x可以分解出k个"10"，即说明x可以分解出k个"2*5"
    // x = n! = (2^a) * (5^b) * ... * (y^i)，答案为min(a, b)；由于5>2，b == min(a, b)
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
