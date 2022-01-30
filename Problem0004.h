//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0004_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0004_H

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        auto total = (int) nums1.size() + (int) nums2.size();
        if (total % 2) {
            return helper(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            auto left_mid = helper(nums1, 0, nums2, 0, total / 2);
            auto right_mid = helper(nums1, 0, nums2, 0, total / 2 + 1);
            return (left_mid + right_mid) / 2.0;
        }
    }

private:
    int helper(const vector<int> &nums1, const int st1, const vector<int> &nums2, const int st2, const int k) {
        // k从1开始计数；nums1是长度较小的数组，nums2是长度较长的数组；st1，s2分别是数组的起始位置
        if (nums1.size() - st1 > nums2.size() - st2) {  // nums1比nums2长
            return helper(nums2, st2, nums1, st1, k);
        }
        if (k == 1) {
            if (st1 == nums1.size()) {
                return nums2[st2];
            } else {
                return min(nums1[st1], nums2[st2]);
            }
        }
        if (st1 == nums1.size()) {
            // nums1为空（无需测试nums2，前面已保证len(nums2) > len(num1）
            return nums2[st2 + k - 1];
        }
        auto next1 = min(st1 + k / 2, (int) nums1.size());
        auto next2 = min(st2 + k - k / 2, (int) nums2.size());
        if (nums1[next1 - 1] > nums2[next2 - 1]) {
            // 舍弃nums2的左半部，舍弃nums1的右半部
            return helper(nums1, st1, nums2, next2, k - (next2 - st2));
        } else {
            // 舍弃nums2的右半部，舍弃nums1的左半部
            return helper(nums1, next1, nums2, st2, k - (next1 - st1));
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0004_H
