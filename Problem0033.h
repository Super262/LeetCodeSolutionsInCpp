//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0033_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0033_H

#include <vector>

using namespace std;

class Problem0033 {
    // 经典算法，直接背诵
    // 2步二分，先找分界点，再找target
public:
    int search(const vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        // 先找到分界点(我们假定分界点是左区间的最大值)
        int l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (target >= nums[0]) {
            r = l;
            l = 0;
        } else {
            l = l + 1;
            r = (int) nums.size() - 1;
        }
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[r] == target) {
            return r;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0033_H
