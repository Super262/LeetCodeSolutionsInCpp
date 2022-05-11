//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0039_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0039_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(const vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        temp.reserve(candidates.size());
        dfs(candidates, target, 0, temp, result);
        return result;
    }

private:
    void dfs(const vector<int> &nums,
             const int target,
             const int c_idx,
             vector<int> &temp,
             vector<vector<int>> &result) {
        if (target == 0) {
            result.emplace_back(temp);
            return;
        }
        if (c_idx == (int) nums.size()) {
            return;
        }
        // 技巧：渐进式加入当前元素，最后再还原到初始状态
        for (int i = 0; nums[c_idx] * i <= target; ++i) {
            dfs(nums, target - nums[c_idx] * i, c_idx + 1, temp, result);
            temp.emplace_back(nums[c_idx]);
        }
        for (int i = 0; nums[c_idx] * i <= target; ++i) {
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0039_H
