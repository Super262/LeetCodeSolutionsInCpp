//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0476_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0476_H

class Solution {
    // 首先求出num的"有效位"数量bits_cnt，再获得num的反码~num
    // ~num的二进制包含的高位全为1，因为num的高位全为0；因此，我们将(1<<bits_cnt)-1和~num异或，去掉前导1，获得答案
public:
    int findComplement(int num) {
        int bits_cnt = 0;
        for (auto x = num; x > 0; x >>= 1) {
            ++bits_cnt;
        }
        return (int) (~num & ((1ll << bits_cnt) - 1));  // 用long long避免溢出
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0476_H
