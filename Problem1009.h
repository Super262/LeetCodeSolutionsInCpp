//
// Created by Fengwei Zhang on 3/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1009_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1009_H

class Problem1009 {
    // 求补码，模版题
public:
    int bitwiseComplement(int n) {
        if (!n) {
            return 1;
        }
        int ones_cnt = 0;
        for (auto x = n; x > 0; x >>= 1) {
            ++ones_cnt;
        }
        return (int) (~n & ((1ll << ones_cnt) - 1));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1009_H
