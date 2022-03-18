//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0493_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0493_H

#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        const auto n = (int) nums.size();
        int temp[n];
        return mergeSort(nums, 0, n - 1, temp);
    }

private:
    int mergeSort(vector<int> &nums, const int left, const int right, int temp[]) {
        if (left >= right) {
            return 0;
        }
        const auto mid = left + (right - left) / 2;
        auto result = mergeSort(nums, left, mid, temp) + mergeSort(nums, mid + 1, right, temp);
        auto l = left, r = mid + 1;
        //   以下2种写法均可
        // 左计数
        while (r <= right) {
            while (l <= mid && (long long) nums[l] <= 2 * (long long) nums[r]) {
                ++l;
            }
            result += mid - l + 1;
            ++r;
        }
        // 右计数
        // while (l <= mid) {
        //     while (r <= right && (long long) nums[l] > 2 * (long long) nums[r]) {
        //         ++r;
        //     }
        //     result += r - (mid + 1);
        //     ++l;
        // }

        // 归并排序
        l = left, r = mid + 1;
        auto tt = left;
        while (l <= mid && r <= right) {
            if (nums[l] <= nums[r]) {
                temp[tt++] = nums[l++];
            } else {
                temp[tt++] = nums[r++];
            }
        }
        while (l <= mid) {
            temp[tt++] = nums[l++];
        }
        while (r <= right) {
            temp[tt++] = nums[r++];
        }
        for (int i = left; i <= right; ++i) {  // 不要忘记最后的拷贝步骤
            nums[i] = temp[i];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0493_H
