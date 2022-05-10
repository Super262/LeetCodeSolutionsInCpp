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
    vector<string> generateParenthesis(const int n) {
        vector<string> result;
        string temp;
        temp.reserve(2 * n);
        dfs(n, 0, 0, temp, result);
        return result;
    }

private:
    void dfs(const int n, const int left_cnt, const int right_cnt, string &temp, vector<string> &result) {
        if (left_cnt == n && right_cnt == n) {
            result.emplace_back(temp);
            return;
        }
        if (left_cnt < n) {
            temp.push_back('(');
            dfs(n, left_cnt + 1, right_cnt, temp, result);
            temp.pop_back();
        }
        if (right_cnt < n && right_cnt < left_cnt) {
            temp.push_back(')');
            dfs(n, left_cnt, right_cnt + 1, temp, result);
            temp.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0022_H
