//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0476_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0476_H

class Solution {
public:
    int findComplement(int num) {
        if (!num) {
            return 1;
        }
        int ones_cnt = 0;
        for (auto x = num; x > 0; x >>= 1) {
            ++ones_cnt;
        }
        // ~num的二进制包含前导1，因为num有前导0：通过XOR去掉前导1
        return (int) (~num & ((1ll << ones_cnt) - 1));  // 用long long避免溢出
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0476_H
