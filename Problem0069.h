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
        long long left = 0;
        long long right = x;
        while (left < right) {
            auto mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int) left;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0069_H
