//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0040_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0040_H

#include <vector>

using namespace std;

class Problem0040 {
private:
    void dfs(const vector<int> &candidates,
             vector<bool> &visited,
             const int cIdx,
             const int target,
             vector<int> &temp,
             vector<vector<int>> &result) {
        if (target == 0) {
            result.emplace_back(vector<int>(temp));
            return;
        }
        if (cIdx == (int) candidates.size()) {
            return;
        }
        for (int i = cIdx; i < (int) candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {  // 避免重复的组合！！
                continue;
            }
            if (candidates[i] > target) {  // 必要的剪枝！！
                continue;
            }
            visited[i] = true;
            temp.emplace_back(candidates[i]);
            dfs(candidates, visited, i + 1, target - candidates[i], temp, result);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(candidates.size(), false);
        dfs(candidates, visited, 0, target, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0040_H
