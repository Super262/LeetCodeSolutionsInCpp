//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0046_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0046_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0046 {
private:
    void dfs(const vector<int> &nums,
             bool visited[],
             vector<int> &path,
             vector<vector<int>> &result) {
        if (path.size() == nums.size()) {
            result.emplace_back(vector<int>(path));
            return;
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            path.emplace_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, path, result);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        bool visited[nums.size()];
        memset(visited, 0, sizeof visited);
        dfs(nums, visited, path, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0046_H
