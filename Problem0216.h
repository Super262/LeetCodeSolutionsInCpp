//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0216_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0216_H

class Problem0216 {
private:
    void dfs(vector <vector<int>> &result,
             vector<int> &temp,
             const int currentNum,
             const int n,
             const int currentSum,
             const int k) {
        if (currentSum == n && temp.size() == k) {  // 序列和为n，包含的个数为k，满足要求
            result.emplace_back(vector<int>(temp));
            return;
        }
        if (currentNum == 9 || temp.size() == k) {  // 已搜索到最后一个数字或序列长度达到上限
            return;
        }
        for (int i = currentNum + 1; i <= 9; ++i) {
            temp.emplace_back(i);
            dfs(result, temp, i, n, currentSum + i, k);
            temp.pop_back();
        }
    }

    vector <vector<int>> combinationSum3(int k, int n) {
        vector <vector<int>> result;
        vector<int> temp;
        dfs(result, temp, 0, n, 0, k);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0216_H
