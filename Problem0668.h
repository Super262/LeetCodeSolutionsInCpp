//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0668_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0668_H

#include <iostream>

using namespace std;

class Solution {
    // 经观察发现，对于任意数字x，乘法表第i行有(x/i)个比x小的数（某行为{i, 2*i, 3*i, ... n*i}）
    // 因此我们使用二分查找，找到第k个数x，即比x小的数字有k个
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
