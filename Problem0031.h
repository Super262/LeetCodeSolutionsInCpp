//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0031_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0031_H

#include <vector>

using namespace std;

class Problem0031 {
private:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 3) {  // 特殊情况：序列长度小于3，直接反序
            reverse(nums.begin(), nums.end());
            return;
        }
        int k = (int) nums.size() - 2;
        while (k >= 0 && nums[k] >= nums[k + 1]) {  // 找到递减序列前的元素
            --k;
        }
        if (k < 0) {  // 整个序列为递减序列
            reverse(nums.begin(), nums.end());
            return;
        }
        auto nextGreIdx = k + 1;
        while (nextGreIdx < nums.size() && nums[nextGreIdx] > nums[k]) {
            // 在递减序列中搜索比nums[k]大的最小元素
            ++nextGreIdx;
        }
        --nextGreIdx;
        swap(nums[nextGreIdx], nums[k]);  // 交换
        reverse(nums.begin() + k + 1, nums.end()); // 反序原降序序列
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0031_H
