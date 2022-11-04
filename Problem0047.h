//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0047_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0047_H

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Problem0047 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> temp;
        bool visited[nums.size()];
        memset(visited, 0, sizeof visited);
        sort(nums.begin(), nums.end());
        temp.reserve(nums.size());
        dfs(nums, 0, temp, visited, result);
        return result;
    }

private:
    void dfs(const vector<int> &nums, const int idx, vector<int> &temp, bool visited[], vector<vector<int>> &res) {
        if (idx == (int) nums.size()) {
            res.emplace_back(temp);
            return;
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            temp.emplace_back(nums[i]);
            visited[i] = true;
            dfs(nums, idx + 1, temp, visited, res);
            visited[i] = false;
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0047_H
