//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0015_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0015_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0015 {
    // "双指针"的前提：序列有序
    // "双指针"最多能把O(n^2)的运算优化为O(n)
private:
    // 思路：固定i，移动j和k（i < j < k）
    // 注意去重！
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {  // 去重
                continue;
            }
            for (int j = i + 1, k = (int) nums.size() - 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {  // 去重
                    continue;
                }
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) {  // 测试k是否还能向左移动
                    --k;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0015_H
