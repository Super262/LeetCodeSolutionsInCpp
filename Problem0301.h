//
// Created by Fengwei Zhang on 11/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0301_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0301_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(const string &s) {
        int left_cnt = 0;  // 待删掉的左括号的数量
        int right_cnt = 0;  // 待删掉的右括号的数量
        for (const auto &ch: s) {
            if (ch == '(') {
                ++left_cnt;
            } else if (ch == ')') {
                if (left_cnt == 0) {
                    ++right_cnt;
                } else {
                    --left_cnt;
                }
            }
        }
        vector<string> answer;
        dfs(s, 0, "", 0, left_cnt, right_cnt, answer);
        return answer;
    }

private:
    void dfs(const string &s,  // 原序列
             int si,  // 当前字符索引
             string current,  // 被操作后的序列
             int cur_diff,  // current的(左括号数量 - 右括号数量)
             int left_cnt,
             int right_cnt,
             vector<string> &answer) {
        if (si == (int) s.size()) {
            if (!cur_diff) {
                answer.push_back(current);
            }
            return;
        }
        if (s[si] != '(' && s[si] != ')') {
            dfs(s, si + 1, current + s[si], cur_diff, left_cnt, right_cnt, answer);
            return;
        }
        if (s[si] == '(') {
            int k = si;
            while (k < (int) s.size() && s[k] == '(') {
                ++k;
            }
            left_cnt -= k - si;
            for (int i = k - si; i >= 0; --i) {
                if (left_cnt >= 0) {
                    dfs(s, k, current, cur_diff, left_cnt, right_cnt, answer);
                }
                current += '(';
                ++cur_diff;
                ++left_cnt;
            }
            return;
        }
        if (s[si] == ')') {
            int k = si;
            while (k < (int) s.size() && s[k] == ')') {
                ++k;
            }
            right_cnt -= k - si;
            for (int i = k - si; i >= 0; --i) {
                if (right_cnt >= 0 && cur_diff >= 0) {
                    dfs(s, k, current, cur_diff, left_cnt, right_cnt, answer);
                }
                current += ')';
                --cur_diff;
                ++right_cnt;
            }
            return;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0301_H
