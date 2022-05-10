//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0022_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0022_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 合法的括号序列：left_cnt <= n, right_cnt <= n && left_cnt >= right_cnt
    // 直接DFS
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        temp.reserve(2 * n);
        dfs(n, 0, 0, temp, ans);
        return ans;
    }

private:
    void dfs(int n, int left_cnt, int right_cnt, string &temp, vector<string> &ans) {
        if (left_cnt == n && right_cnt == n) {
            ans.emplace_back(temp);
            return;
        }
        if (left_cnt < n) {
            temp += '(';
            dfs(n, left_cnt + 1, right_cnt, temp, ans);
            temp.pop_back();
        }
        if (left_cnt <= n && right_cnt < left_cnt) {
            temp += ')';
            dfs(n, left_cnt, right_cnt + 1, temp, ans);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0022_H
