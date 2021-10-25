//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0047_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0047_H

#include <vector>

using namespace std;

class Problem0047 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> temp(nums.size(), 0);
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, temp, visited, result);
        return result;
    }

    void dfs(const vector<int> &nums, const int numIdx, vector<int> &temp, vector<bool> &visited,
             vector<vector<int>> &result) {
        if (numIdx == (int) nums.size()) {
            result.emplace_back(temp);
            return;
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            temp[numIdx] = nums[i];
            visited[i] = true;
            dfs(nums, numIdx + 1, temp, visited, result);
            visited[i] = false;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0047_H
