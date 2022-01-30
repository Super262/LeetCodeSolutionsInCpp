//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0011_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0011_H

#include <vector>

using namespace std;

class Solution {
    // 直接背诵，双指针算法经典题目
public:
    int maxArea(const vector<int> &height) {
        int result = 0;
        int l = 0;
        int r = (int) height.size() - 1;
        while (l < r) {
            result = max(result, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0011_H
