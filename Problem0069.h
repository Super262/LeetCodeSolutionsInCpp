//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0069_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0069_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 二分查找
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (mid * mid <= x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (int) l;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0069_H
