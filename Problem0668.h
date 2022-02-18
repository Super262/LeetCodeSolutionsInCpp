//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0668_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0668_H

#include <iostream>

using namespace std;

class Solution {
    // 经典算法，必须掌握：二分法，第i行有x/i个比x小的数（某行为{i, 2*i, 3*i, ... n*i}）
    // https://www.acwing.com/solution/content/524/
public:
    int findKthNumber(const int m, const int n, const int k) {
        int l = 1;  // 乘法表的最小数
        int r = m * n;  // 乘法表的最大数
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (smallerCount(mid, m, n) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    int smallerCount(const int x, const int m, const int n) {  // 比x小的数的个数
        int total = 0;
        for (int i = 1; i <= m; ++i) {
            total += min(x / i, n);
        }
        return total;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0668_H
