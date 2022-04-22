//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1015_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1015_H

#include <algorithm>

using namespace std;

class Solution {
    // 参考 AcWing 202
    // 由题意可知，我们希望找到最小的x，使 k 能整除 (10^x - 1) / 9
    // 因此，10^x = 1 (mod 9*k)，即 10^x 和 9*k 互质；根据欧拉定理与费马小定理，x是phi(9*k)的约数
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {  // 9*k应和10互质
            return -1;
        }
        auto phi = eulerPhi(9 * k);
        auto ans = phi;
        for (int i = 1; i <= phi / i; ++i) {  // 枚举phi的因子
            if (phi % i) {
                continue;
            }
            if (quick_power(10, i, 9 * k) == 1) {  // 找到合适的因子
                return i;
            }
            if (quick_power(10, phi / i, 9 * k) == 1) {
                ans = min(ans, phi / i);
            }
        }
        return ans;
    }

private:
    int quick_power(int a, int x, const int m) {
        int ans = 1;
        while (x) {
            if (x & 1) {
                ans = (int) ((long long) ans * a % m);
            }
            a = (int) ((long long) a * a % m);
            x >>= 1;
        }
        return ans;
    }

    int eulerPhi(int x) {
        auto ans = x;
        for (int i = 2; i <= x / i; ++i) {
            if (x % i) {
                continue;
            }
            ans = ans / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
        if (x > 1) {
            ans = ans / x * (x - 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1015_H
