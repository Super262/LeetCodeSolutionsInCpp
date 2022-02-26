//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0762_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0762_H

#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        if (left > right) {
            return 0;
        }
        unordered_set<int> primes({2, 3, 5, 7, 11, 13, 17, 19});
        int res = 0;
        for (auto i = left; i <= right; ++i) {
            int counter = 0;
            for (auto j = i; j > 0; j >>= 1) {
                counter += j & 1;
            }
            if (primes.count(counter)) {
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0762_H
