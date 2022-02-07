//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0216_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0216_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(result, temp, 1, n, 0, k);
        return result;
    }

private:
    void dfs(vector<vector<int>> &result,
             vector<int> &temp,
             const int num,
             const int n,
             const int sum,
             const int k) {
        if (sum == n && temp.size() == k) {  // 序列和为n，包含的个数为k，满足要求
            result.emplace_back(temp);
            return;
        }
        if (num == 10 || temp.size() == k) {  // 已搜索到最后一个数字或序列长度达到上限
            return;
        }
        for (int i = num; i <= 9; ++i) {
            temp.emplace_back(i);
            dfs(result, temp, i + 1, n, sum + i, k);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0216_H
