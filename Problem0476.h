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
        // 将[0:ones_cnt-1]取反，忽略最高位（取反后为0）；用long long避免溢出
        return (int) (~num & ((1ll << ones_cnt) - 1));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0476_H
