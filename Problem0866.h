//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0866_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0866_H

#include <string>

using namespace std;

class Solution {
    // 我们从最小的回文数开始逐一枚举，直到找到一个大于等于 N 的素数为止。
    // 这里有一个结论，除 11 以外，偶数长度的回文数不可能是素数。这里用到了被 11 整除的数的性质，奇数位之和等于偶数位之和的数一定能被 11 整除。
    // 我们枚举奇数长度回文数的前半部分，这样第一次遇到素数且大于 N 就可以停下了。
public:
    int primePalindrome(int n) {
        if (n > 7 && n <= 11) {
            return 11;
        }
        for (int i = 1; i < INT_MAX; ++i) {
            auto x = makePalindrome(i);
            if (x >= n && isPrime(x)) {
                return x;
            }
        }
        return -1;
    }

private:
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int x = 2; x <= n / x; ++x) {
            if (n % x == 0) {
                return false;
            }
        }
        return true;
    }

    int makePalindrome(int x) {  // 构建回文数：x[0:-1] + reverse(x)
        auto l = to_string(x);
        auto r = l;
        reverse(r.begin(), r.end());
        l.pop_back();
        return stoi(l + r);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0866_H
