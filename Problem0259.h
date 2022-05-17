//
// Created by Fengwei Zhang on 5/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0259_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0259_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 不要被题意迷惑：任意3个不相等的数字，一定满足i<j<k，题目只是要求我们找到3个不同的数字以满足题意
    // 排序 + 双指针（正确性：两指针不会反向移动） + 贪心
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < (int) nums.size() - 2; ++i) {
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return ans;
    }

private:
    int twoSumSmaller(const vector<int> &nums, int st, int target) {
        int ans = 0;
        auto l = st;
        auto r = (int) nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] >= target) {
                --r;
            } else {
                ans += r - l;  // nums[l]和nums[l+1:r]中任意数字的配对都满足要求
                ++l;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0259_H
