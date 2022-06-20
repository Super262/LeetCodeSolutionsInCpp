//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0581_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0581_H

#include <vector>

using namespace std;

class Solution {
    // 根据题意，我们需要找到1个最短的区间nums[i:j]，满足nums[0:i-1]中的元素小于区间nums[i:j]中的任意元素、nums[j+1:n-1]中的元素大于区间nums[i:j]中的任意元素
    // 首先我们先分别从左侧、右侧找到逆序发生的位置，确定初始区间；再根据区间内元素和区间外元素的大小关系，向左、向右扩展区间
public:
    int findUnsortedSubarray(const vector<int> &nums) {
        int l = 0;
        int r = (int) nums.size() - 1;
        // 分别找到两侧逆序发生的位置
        while (l + 1 < (int) nums.size() && nums[l + 1] >= nums[l]) {
            ++l;
        }
        if (l == r) {  // 全部有序，直接返回0
            return 0;
        }
        while (r - 1 >= 0 && nums[r - 1] <= nums[r]) {
            --r;
        }
        // 若nums[l+1:r-1]中有元素在nums[l]前或在nums[r]后，扩展目标数组长度
        for (int i = l + 1; i < (int) nums.size(); ++i) {
            while (l >= 0 && nums[l] > nums[i]) {
                --l;
            }
        }
        for (int i = r - 1; i >= 0; --i) {
            while (r < (int) nums.size() && nums[r] < nums[i]) {
                ++r;
            }
        }
        return r - l - 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0581_H
