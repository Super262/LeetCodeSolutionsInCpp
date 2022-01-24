//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0491_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0491_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(const vector<int> &nums) {
        vector<int> temp;
        vector<vector<int>> result;
        dfs(0, nums, temp, result);
        return result;
    }

private:
    void dfs(const int idx, const vector<int> &nums, vector<int> &temp, vector<vector<int>> &result) {
        if (temp.size() > 1) {
            result.emplace_back(temp);
        }
        if (idx >= (int) nums.size()) {
            return;
        }
        unordered_set<int> existed;  // 在递归的每一层内使用集合判重
        for (auto i = idx; i < nums.size(); ++i) {
            if (!temp.empty() && temp.back() > nums[i]) {
                continue;
            }
            if (existed.count(nums[i])) {
                continue;
            }
            existed.insert(nums[i]);
            temp.emplace_back(nums[i]);
            dfs(i + 1, nums, temp, result);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0491_H
