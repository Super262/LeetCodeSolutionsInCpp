//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0869_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0869_H

#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        for (long i = 1; i <= INT_MAX; i <<= 1) {
            if (isAnagram((int) i, n)) {
                return true;
            }
        }
        return false;
    }

private:
    bool isAnagram(int a, int b) {
        const int M = 10;
        int counter[M];
        memset(counter, 0, sizeof counter);
        while (a) {
            ++counter[a % M];
            a /= M;
        }
        while (b) {
            --counter[b % M];
            b /= M;
        }
        for (const auto &x: counter) {
            if (x) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0869_H
