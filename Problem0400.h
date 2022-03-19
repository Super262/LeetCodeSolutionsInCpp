//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0400_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0400_H

#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(long long n) {
        long long k = 1;  // n是k位数
        long long t = 9;  // k位数共t个
        long long s = 1;  // 最小的k位数是t
        while (n > k * t) {
            n -= k * t;
            ++k;
            t *= 10;
            s *= 10;
        }
        s += (n + k - 1) / k - 1;  // 计算上取整(n / k)，得到n位数字所在的整数
        n = n % k ? n % k : k;
        return to_string(s)[n - 1] - '0';
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0400_H
