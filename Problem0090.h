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
public:

    void dfs(const int idx, const vector<int> &nums, vector<int> &temp, vector<vector<int>> &result) {
        if (idx == (int) nums.size()) {
            result.emplace_back(vector<int>(temp));
            return;
        }
        int k = idx + 1;
        while (k < nums.size() && nums[k] == nums[idx]) {
            ++k;
        }
        for (int i = 0; i <= k - idx; ++i) {  // 从当前数字中选择0～k - i个
            dfs(k, nums, temp, result);
            temp.emplace_back(nums[idx]);
        }
        for (int i = 0; i <= k - idx; ++i) { // 弹出k-i个数字
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        dfs(0, nums, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0090_H
