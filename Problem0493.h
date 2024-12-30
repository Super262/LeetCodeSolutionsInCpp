//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0493_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0493_H

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
    // 基于归并排序，统计逆序对个数
    // 由于逆序对的定义和元素大于的定义不同（逆序：nums[i]>2*nums[j]，大于：nums[i]>nums[j]），我们拆分归并、计算逆序对这两步
public:
    int reversePairs(vector<int>& nums) {
        auto n = nums.size();
        if (!n) {
            return 0;
        }
        int *temp = (int *) malloc(n * sizeof(int));
        auto answer = myMergeCount(nums, 0, n - 1, temp);
        free(temp);
        return static_cast<int>(answer);
    }
private:
    size_t myMergeCount(vector<int>& nums, size_t st, size_t ed, int *temp) {
        if (st >= ed) {
            return 0;
        }
        auto mid = st + (ed - st) / 2;
        auto answer = myMergeCount(nums, st, mid, temp) + myMergeCount(nums, mid + 1, ed, temp);
        auto l = st;
        auto r = mid + 1;
        // 统计逆序对：以下2种写法均可
        // 左计数（固定r，移动l）
        while (r <= ed) {
            while (l <= mid && nums[l] <= 2 * (long long) nums[r]) { // 类型转换，避免overflow
                ++l;
            }
            answer += mid - l + 1;
            ++r;
        }
        // 右计数（固定l，移动r）
        // while (l <= mid) {
        //     while (r <= ed && nums[l] > 2 * (long long) nums[r]) {
        //         ++r;
        //     }
        //     answer += r - (mid + 1);
        //     ++l;
        // }

        // 归并
        l = st;
        r = mid + 1;
        auto t = st;
        while (l <= mid && r <= ed) {
            if (nums[l] < nums[r]) {
                temp[t] = nums[l];
                ++l;
            }
            else {
                temp[t] = nums[r];
                ++r;
            }
            ++t;
        }
        while (l <= mid) {
            temp[t] = nums[l];
            ++t;
            ++l;
        }
        while (r <= ed) {
            temp[t] = nums[r];
            ++t;
            ++r;
        }
        for (auto i = st; i <= ed; ++i) {
            nums[i] = temp[i];
        }
        return answer;
    }
};

#endif // LEETCODESOLUTIONSINCPP_PROBLEM0493_H
