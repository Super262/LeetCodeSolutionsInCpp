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
        int extraLeftCnt = 0;  // 待删掉的左括号的数量
        int extraRightCnt = 0;  // 待删掉的右括号的数量
        for (const auto &ch: s) {
            if (ch == '(') {
                ++extraLeftCnt;
            } else if (ch == ')') {
                if (extraLeftCnt == 0) {
                    ++extraRightCnt;
                } else {
                    --extraLeftCnt;
                }
            }
        }
        vector<string> answer;
        dfs(s, 0, "", 0, extraLeftCnt, extraRightCnt, answer);
        return answer;
    }

private:
    void dfs(const string &s,  // 原序列
             int chIdx,  // 当前字符索引
             string current,  // 被操作后的序列
             int curDiff,  // current的(左括号数量 - 右括号数量)
             int extraLeftCnt,
             int extraRightCnt,
             vector<string> &answer) {
        if (chIdx == (int) s.size()) {
            if (curDiff == 0) {
                answer.push_back(current);
            }
            return;
        }
        if (s[chIdx] != '(' && s[chIdx] != ')') {
            dfs(s, chIdx + 1, current + s[chIdx], curDiff, extraLeftCnt, extraRightCnt, answer);
            return;
        }
        if (s[chIdx] == '(') {
            int k = chIdx;
            while (k < (int) s.size() && s[k] == '(') {
                ++k;
            }
            extraLeftCnt -= k - chIdx;
            for (int i = k - chIdx; i >= 0; --i) {
                if (extraLeftCnt >= 0) {
                    dfs(s, k, current, curDiff, extraLeftCnt, extraRightCnt, answer);
                }
                current += '(';
                ++curDiff;
                ++extraLeftCnt;
            }
            return;
        }
        if (s[chIdx] == ')') {
            int k = chIdx;
            while (k < (int) s.size() && s[k] == ')') {
                ++k;
            }
            extraRightCnt -= k - chIdx;
            for (int i = k - chIdx; i >= 0; --i) {
                if (extraRightCnt >= 0 && curDiff >= 0) {
                    dfs(s, k, current, curDiff, extraLeftCnt, extraRightCnt, answer);
                }
                current += ')';
                --curDiff;
                ++extraRightCnt;
            }
            return;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0301_H
