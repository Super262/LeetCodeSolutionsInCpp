//
// Created by Fengwei Zhang on 4/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0859_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0859_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool buddyStrings(const string &s, const string &goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int diff_cnt = 0;
        int diff_pos[3];
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] == goal[i]) {
                continue;
            }
            diff_pos[diff_cnt] = i;
            ++diff_cnt;
            if (diff_cnt > 2) {
                return false;
            }
        }
        if (diff_cnt == 1) {
            return false;
        }
        if (!diff_cnt) {  // 若s和goal相等，则s中必定包含至少2个相同的字符
            unordered_set<char> chs(s.begin(), s.end());
            return chs.size() < s.size();
        }
        // 若s不等于goal，则对应位置的字符相等
        return s[diff_pos[0]] == goal[diff_pos[1]] && s[diff_pos[1]] == goal[diff_pos[0]];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0859_H
