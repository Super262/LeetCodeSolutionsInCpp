//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0338_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0338_H

#include <vector>

using namespace std;

class Solution {
    // 递推式解法，直接背诵
    // f[i]：二进制数i中"1"个数；若i有n位，f[i]等于第2～n位中"1"的个数加上最后位"1"的个数
public:
    vector<int> countBits(const int &n) {
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i >> 1] + (i & 1);
        }
        return f;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0338_H
