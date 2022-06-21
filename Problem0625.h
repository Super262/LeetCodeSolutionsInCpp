//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0625_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0625_H

class Solution {
    // 我们要得到数字ans，ans的每位的乘积等于num；贪心算法：由于ans的每位可重复，我们尝试将较大的因子（2～9）加入低位
public:
    int smallestFactorization(int num) {
        if (num == 1) {
            return num;
        }
        long long ans = 0;
        long long base = 1;
        for (int i = 9; i >= 2; --i) {
            while (num % i == 0) {
                ans += base * i;
                base *= 10;
                num /= i;
            }
        }
        if (num == 1 && ans < (2ll << 30) - 1) {
            return (int) ans;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0625_H
