//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0204_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0204_H

#include <cstring>

class Solution {
    // 同AcWing0868，直接背诵！
public:
    int countPrimes(const int n) {
        if (n == 0) {
            return 0;
        }
        int primes[n];
        bool filtered[n];
        memset(filtered, 0, sizeof filtered);
        int cnt = 0;
        for (int f = 2; f <= n - 1; ++f) {
            if (!filtered[f]) {
                primes[cnt++] = f;
            }
            for (int j = 0; primes[j] <= (n - 1) / f; ++j) {
                filtered[primes[j] * f] = true;
                if (f % primes[j] == 0) {
                    break;
                }
            }
        }
        return cnt;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0204_H
