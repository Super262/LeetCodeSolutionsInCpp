//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0540_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0540_H

#include <vector>

using namespace std;

class Solution {
    // 二分查找经典题目
    // 给定序列[1,1,2,3,3,4,4,8,8]，在结尾加入8+1=9，得到[1,1,2,3,3,4,4,8,8,9]。
    // 我们将数字结对分组，得到[(1,1),(2,3),(3,4),(4,8),(8,9)]。
    // 经观察发现，存在组编号m，使m及其右侧的分组中2个元素不相等，m左侧分组中元素2个元素相等
public:
    int singleNonDuplicate(vector<int> &nums) {
        // 暂时忽略最后一个分组（(a[n-1], a[n-1] + 1)）
        int l = 0, r = (int) (nums.size() / 2 - 1);  // 二分查找分组编号（将a[0]~a[n-2]分组）
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (nums[mid * 2] != nums[mid * 2 + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (r < 0 || nums[r * 2] == nums[r * 2 + 1]) {  // nums长度为1时，r<0
            return nums.back();
        }
        return nums[2 * r];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0540_H
