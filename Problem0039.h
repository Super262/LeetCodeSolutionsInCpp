//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0039_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0039_H

#include <vector>

using namespace std;

class Problem0039 {
private:
    void dfs(const vector<int> &candidates,
             const int target,
             const int cIdx,
             vector<int> &temp,
             vector<vector<int>> &result) {
        if (target == 0) {
            result.emplace_back(vector<int>(temp));
            return;
        }
        if (cIdx == (int) candidates.size()) {
            return;
        }
        for (int i = 0; candidates[cIdx] * i <= target; ++i) {
            dfs(candidates, target - candidates[cIdx] * i, cIdx + 1, temp, result);
            temp.emplace_back(candidates[cIdx]);
        }
        for (int i = 0; candidates[cIdx] * i <= target; ++i) {
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(candidates, target, 0, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0039_H
