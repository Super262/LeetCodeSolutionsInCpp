//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0386_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0386_H

#include <vector>

using namespace std;

class Solution {
    // 使用DFS模拟对字典树的搜索，无需真正建立字典树
public:
    vector<int> lexicalOrder(const int &n) {
        vector<int> res;
        for (int st = 1; st <= 9; ++st) {
            dfs(st, n, res);
        }
        return res;
    }

private:
    void dfs(const int &idx, const int &n, vector<int> &answer) {
        if (idx > n) {
            return;
        }
        answer.push_back(idx);
        auto temp = idx * 10;
        for (int i = 0; i <= 9; ++i) {
            temp += i;
            dfs(temp, n, answer);
            temp -= i;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0386_H
