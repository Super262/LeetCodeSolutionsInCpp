//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0204_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0204_H

#include <cstring>

class Solution {
public:
    int countPrimes(const int &n) {
        if (n == 0) {
            return 0;
        }
        // 同AcWing0868，直接背诵！
        int result = 0;
        int primes[n];
        bool isFiltered[n];
        memset(isFiltered, 0, sizeof isFiltered);
        for (int f = 2; f <= n - 1; ++f) {
            if (!isFiltered[f]) {
                primes[result++] = f;
            }
            for (int j = 0; primes[j] <= (n - 1) / f; ++j) {
                isFiltered[primes[j] * f] = true;
                if (f % primes[j] == 0) {
                    break;
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0204_H
