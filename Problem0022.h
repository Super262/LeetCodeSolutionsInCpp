//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0022_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0022_H

#include <vector>
#include <string>

using namespace std;

class Problem0022 {
private:
    // 合法的括号序列：leftCnt < n, rightCnt < n && leftCnt > rightCnt
    void dfs(const int n, const int leftCnt, const int rightCnt, string &temp, vector<string> &result) {
        if (leftCnt == n && rightCnt == n) {
            result.emplace_back(string(temp));
            return;
        }
        if (leftCnt < n) {
            temp.push_back('(');
            dfs(n, leftCnt + 1, rightCnt, temp, result);
            temp.pop_back();
        }
        if (rightCnt < n && rightCnt < leftCnt) {
            temp.push_back(')');
            dfs(n, leftCnt, rightCnt + 1, temp, result);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(const int n) {
        vector<string> result;
        string temp;
        dfs(n, 0, 0, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0022_H
