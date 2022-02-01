//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0040_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0040_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, const int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(candidates.size(), false);
        dfs(candidates, visited, 0, target, temp, result);
        return result;
    }

private:
    void dfs(const vector<int> &nums,
             vector<bool> &visited,
             const int idx,
             const int target,
             vector<int> &temp,
             vector<vector<int>> &res) {
        if (target == 0) {
            res.emplace_back(temp);
            return;
        }
        if (idx == (int) nums.size()) {
            return;
        }
        for (int i = idx; i < (int) nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1] && !visited[i - 1]) {  // 避免重复的组合！！
                continue;
            }
            if (nums[i] > target) {  // 必要的剪枝！！
                return;
            }
            visited[i] = true;
            temp.emplace_back(nums[i]);
            dfs(nums, visited, i + 1, target - nums[i], temp, res);
            temp.pop_back();
            visited[i] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0040_H
