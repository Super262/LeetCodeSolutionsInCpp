//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0643_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0643_H

#include <vector>

using namespace std;

class Solution {
    // 维护长度为k的滑动窗口，计算窗口内元素的平均值，更新答案
public:
    double findMaxAverage(const vector<int> &nums, int k) {
        int ans = INT_MIN;
        for (int l = 0, r = 0, sum = 0; r < (int) nums.size(); ++r) {
            sum += nums[r];
            if (r - l + 1 > k) {
                sum -= nums[l];
                ++l;
            }
            if (r - l + 1 == k) {
                ans = max(ans, sum);
            }
        }
        return (double) ans / k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0643_H
