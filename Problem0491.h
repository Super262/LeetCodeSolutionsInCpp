//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0491_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0491_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 直接DFS，枚举所有可能的后继元素；输入包含重复元素，要处理每层（递归树）的重复元素
    // 因为输入序列是无序的，重复元素不相邻，我们不能通过比较相邻元素（nums[i-1]==nums[i]）来忽略重复元素，要使用集合类
public:
    vector<vector<int>> findSubsequences(const vector<int> &nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, nums, temp, ans);
        return ans;
    }

private:
    void dfs(const int idx, const vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
        if (temp.size() > 1) {
            ans.emplace_back(temp);
        }
        if (idx >= (int) nums.size()) {
            return;
        }
        unordered_set<int> existed;  // 在递归的每层，使用集合判重
        for (auto i = idx; i < (int) nums.size(); ++i) {
            if (!temp.empty() && temp.back() > nums[i]) {
                continue;
            }
            if (existed.count(nums[i])) {
                continue;
            }
            existed.insert(nums[i]);
            temp.emplace_back(nums[i]);
            dfs(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0491_H
