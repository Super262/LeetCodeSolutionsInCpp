//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0216_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0216_H

#include <vector>

using namespace std;

class Solution {
    // DFS，注意细节
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(1, n, k, result, temp);
        return result;
    }

private:
    void dfs(const int num,
             const int target,
             const int k,
             vector<vector<int>> &result,
             vector<int> &temp) {
        if (!target && (int) temp.size() == k) {  // 序列和为n，包含的个数为k，满足要求
            result.emplace_back(temp);
            return;
        }
        if (num == 10 || (int) temp.size() == k) {  // 已搜索完最后一个数字或序列长度达到上限
            return;
        }
        for (auto x = num; x <= 9 && x <= target; ++x) {
            temp.emplace_back(x);
            dfs(x + 1, target - x, k, result, temp);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0216_H
