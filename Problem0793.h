//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0793_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0793_H

class Problem0793 {
    // 阶乘x!尾部0的个数是min(a, b)，a是质因子5的个数，b是质因子2的个数；由于5大于2，a等于min(a, b)
    // 我们用二分法查找满足阶乘尾部0的个数小于或等于k的数字，计作g(k)；本题的解为 g(k) - g(k - 1)
public:
    int preimageSizeFZF(int k) {
        return getKZero(k) - getKZero(k - 1);
    }

private:
    long long getKZero(int k) {
        long long l = -1;  // 边界值，可以保证k=0时返回正确的结果
        long long r = 1e18;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (countFactorInFactorial(mid, 5) <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    long long countFactorInFactorial(long long n, long long x) {
        long long ans = 0;
        while (n) {
            ans += n / x;
            n /= x;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0793_H
