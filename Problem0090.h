//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0090_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0090_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Problem0090 {
    // 排序 + DFS，注意细节
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        temp.reserve(nums.size());
        dfs(0, nums, temp, result);
        return result;
    }

private:
    void dfs(const int idx, const vector<int> &nums, vector<int> &temp, vector<vector<int>> &result) {
        if (idx == (int) nums.size()) {
            result.emplace_back(temp);
            return;
        }
        auto k = idx + 1;
        while (k < (int) nums.size() && nums[k] == nums[idx]) {
            ++k;
        }
        for (int i = 0; i <= k - idx; ++i) {  // 选择[0:k-i]个nums[i]
            dfs(k, nums, temp, result);
            temp.emplace_back(nums[idx]);
        }
        for (int i = 0; i <= k - idx; ++i) { // 弹出k-i+1个数字
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0090_H
