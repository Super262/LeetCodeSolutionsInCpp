//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0878_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0878_H

#include <algorithm>

using namespace std;

class Solution {
    // 容斥原理：(A + B) - A & B；具体实现：二分 + GCD
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int M = 1e9 + 7;
        long long l = 1;
        long long r = INT64_MAX;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (countAEB(mid, a, b) >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) (r % M);
    }

private:
    static int gcd(int a, int b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    static long long countAEB(long long n, int a, int b) {  // (A + B) - A & B
        return n / a + n / b - n / ((long long) a * b / gcd(a, b));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0878_H
