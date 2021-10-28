//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0077_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0077_H

#include <vector>

using namespace std;

class Problem0077 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(n, 1, k, temp, result);
        return result;
    }

    void dfs(const int &n, const int &start, const int &k, vector<int> &temp, vector<vector<int>> &result) {
        if (k == 0) {
            result.emplace_back(temp);
            return;
        }
        for (int num = start; num <= n; ++num) {
            temp.emplace_back(num);
            dfs(n, num + 1, k - 1, temp, result);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0077_H
