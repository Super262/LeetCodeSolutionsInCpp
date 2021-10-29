//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0081_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0081_H

#include <vector>

using namespace std;

class Problem0081 {
public:
    bool search(const vector<int> &nums, const int &target) {
        // 时间复杂度：O(n)
        // 优化策略：忽略部分重复元素
        if (nums.empty()) {
            return false;
        }
        int R = (int) nums.size() - 1;
        while (R >= 0 && nums[R] == nums[0]) {
            --R;
        }
        if (R < 0) {  // 所有元素重复
            return nums[0] == target;
        }

        // 二分查找分界点
        int l = 0, r = R;
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
            r = R;
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
