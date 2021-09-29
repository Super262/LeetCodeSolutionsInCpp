//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0004_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0004_H

#include <vector>

using namespace std;

class Problem0004 {
private:
    int findHelper(const vector<int> &nums1, const int s1, const vector<int> &nums2, const int s2, const int k) {
        // k从1开始计数；nums1是长度较小的数组，nums2是长度较长的数组；s1，s2分别是数组的起始位置
        if (nums1.size() - s1 > nums2.size() - s2) {  // nums1比nums2长
            return findHelper(nums2, s2, nums1, s1, k);
        }
        if (k == 1) {
            if (s1 == nums1.size()) {
                return nums2[s2];
            } else {
                return min(nums1[s1], nums2[s2]);
            }
        }
        if (s1 == nums1.size()) {
            return nums2[s2 + k - 1];
        }
        auto nextS1 = min(s1 + k / 2, (int) nums1.size());
        auto nextS2 = min(s2 + k - k / 2, (int) nums2.size());
        if (nums1[nextS1 - 1] > nums2[nextS2 - 1]) {
            return findHelper(nums1, s1, nums2, nextS2, k - (nextS2 - s2));
        } else {
            return findHelper(nums1, nextS1, nums2, s2, k - (nextS1 - s1));
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        auto totalLength = (int) nums1.size() + (int) nums2.size();
        if (totalLength % 2) {
            return findHelper(nums1, 0, nums2, 0, totalLength / 2 + 1);
        } else {
            auto leftMid = findHelper(nums1, 0, nums2, 0, totalLength / 2);
            auto rightMid = findHelper(nums1, 0, nums2, 0, totalLength / 2 + 1);
            return (leftMid + rightMid) / 2.0;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0004_H
