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
        int extra_left_cnt = 0;  // 待删掉的左括号的数量
        int extra_right_cnt = 0;  // 待删掉的右括号的数量
        for (const auto &ch: s) {
            if (ch == '(') {
                ++extra_left_cnt;
            } else if (ch == ')') {
                if (extra_left_cnt == 0) {
                    ++extra_right_cnt;
                } else {
                    --extra_left_cnt;
                }
            }
        }
        vector<string> answer;
        dfs(s, 0, "", 0, extra_left_cnt, extra_right_cnt, answer);
        return answer;
    }

private:
    void dfs(const string &s,  // 原序列
             int ch_idx,  // 当前字符索引
             string current,  // 被操作后的序列
             int cur_diff,  // current的(左括号数量 - 右括号数量)
             int extra_left_cnt,
             int extra_right_cnt,
             vector<string> &answer) {
        if (ch_idx == (int) s.size()) {
            if (cur_diff == 0) {
                answer.push_back(current);
            }
            return;
        }
        if (s[ch_idx] != '(' && s[ch_idx] != ')') {
            dfs(s, ch_idx + 1, current + s[ch_idx], cur_diff, extra_left_cnt, extra_right_cnt, answer);
            return;
        }
        if (s[ch_idx] == '(') {
            int k = ch_idx;
            while (k < (int) s.size() && s[k] == '(') {
                ++k;
            }
            extra_left_cnt -= k - ch_idx;
            for (int i = k - ch_idx; i >= 0; --i) {
                if (extra_left_cnt >= 0) {
                    dfs(s, k, current, cur_diff, extra_left_cnt, extra_right_cnt, answer);
                }
                current += '(';
                ++cur_diff;
                ++extra_left_cnt;
            }
            return;
        }
        if (s[ch_idx] == ')') {
            int k = ch_idx;
            while (k < (int) s.size() && s[k] == ')') {
                ++k;
            }
            extra_right_cnt -= k - ch_idx;
            for (int i = k - ch_idx; i >= 0; --i) {
                if (extra_right_cnt >= 0 && cur_diff >= 0) {
                    dfs(s, k, current, cur_diff, extra_left_cnt, extra_right_cnt, answer);
                }
                current += ')';
                --cur_diff;
                ++extra_right_cnt;
            }
            return;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0301_H
