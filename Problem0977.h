//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0977_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0977_H

#include <vector>

using namespace std;

class Solution {
    // 线性时间的算法：二路归并；由于nums有序，我们设置i指向负数的起点、j指向正数的终点，选取最大值
public:
    vector<int> sortedSquares(const vector<int> &nums) {
        const auto n = (int) nums.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, k = n - 1; i <= j; --k) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k] = nums[i] * nums[i];
                ++i;
            } else {
                res[k] = nums[j] * nums[j];
                --j;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0977_H
