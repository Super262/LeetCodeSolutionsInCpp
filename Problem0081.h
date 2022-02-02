//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0081_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0081_H

#include <vector>

using namespace std;

class Solution {
    // 直接背诵，二分算法经典题目
    // 时间复杂度：O(n)最坏情况下数组元素均相等且不为target，我们需要访问所有位置才能得出结果。
    // 优化策略：忽略部分重复元素
public:
    bool search(const vector<int> &nums, const int &target) {
        if (nums.empty()) {
            return false;
        }
        auto ed = (int) nums.size() - 1;
        while (ed >= 0 && nums[ed] == nums[0]) {
            --ed;
        }
        if (ed < 0) {  // 所有元素重复
            return nums[0] == target;
        }

        // 二分查找分界点
        int l = 0, r = ed;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        // 二分查找目标
        if (target >= nums[0]) {
            r = l;
            l = 0;
        } else {
            l++;
            r = ed;
        }
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[r] == target;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0081_H
