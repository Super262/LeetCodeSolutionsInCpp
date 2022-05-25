//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0376_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0376_H

#include <vector>

using namespace std;

class Solution {
    // 贪心算法，直接背诵！
    // 先清除连续的重复元素，再统计满足条件的三元组（nums[i-1]>nums[i]<nums[i+1] 或 nums[i-1]<nums[i]>nums[i+1]）
public:
    int wiggleMaxLength(vector<int> &nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());  // 清除连续的重复元素
        if (nums.size() < 2) {
            return (int) nums.size();
        }
        int ans = 2;
        for (int i = 1; i + 1 < (int) nums.size(); ++i) {
            if ((nums[i - 1] > nums[i] && nums[i + 1] > nums[i]) || (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0376_H