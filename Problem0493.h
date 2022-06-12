//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0493_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0493_H

#include <vector>

using namespace std;

class Solution {
    // 基于归并排序，统计逆序对个数
    // 由于逆序对的定义和元素大于的定义不同（逆序：nums[i]>2*nums[j]，大于：nums[i]>nums[j]），我们拆分归并、计算逆序对这两步
public:
    int reversePairs(vector<int> &nums) {
        const auto n = (int) nums.size();
        int temp[n];
        return mergeSort(nums, 0, n - 1, temp);
    }

private:
    int mergeSort(vector<int> &nums, const int st, const int ed, int temp[]) {
        if (st >= ed) {
            return 0;
        }
        const auto mid = st + (ed - st) / 2;
        auto ans = mergeSort(nums, st, mid, temp) + mergeSort(nums, mid + 1, ed, temp);
        auto l = st, r = mid + 1;
        // 统计逆序对：以下2种写法均可
        // 左计数（固定r，移动l）
        while (r <= ed) {
            while (l <= mid && (long long) nums[l] <= 2 * (long long) nums[r]) {
                ++l;
            }
            ans += mid - l + 1;
            ++r;
        }
        // 右计数（固定l，移动r）
        // while (l <= mid) {
        //     while (r <= ed && (long long) nums[l] > 2 * (long long) nums[r]) {
        //         ++r;
        //     }
        //     ans += r - (mid + 1);
        //     ++l;
        // }

        // 归并
        l = st, r = mid + 1;
        auto tt = st;
        while (l <= mid && r <= ed) {
            if (nums[l] <= nums[r]) {
                temp[tt++] = nums[l++];
            } else {
                temp[tt++] = nums[r++];
            }
        }
        while (l <= mid) {
            temp[tt++] = nums[l++];
        }
        while (r <= ed) {
            temp[tt++] = nums[r++];
        }
        for (int i = st; i <= ed; ++i) {  // 不要忘记最后的拷贝步骤
            nums[i] = temp[i];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0493_H
