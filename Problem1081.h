//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1081_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1081_H

#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string smallestSubsequence(const string &s) {
        bool is_in_ans[26];
        int last_idx[26];
        memset(is_in_ans, 0, sizeof is_in_ans);
        memset(last_idx, -1, sizeof last_idx);
        for (int i = 0; i < (int) s.size(); ++i) {
            last_idx[s[i] - 'a'] = i;
        }
        string answer;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (is_in_ans[s[i] - 'a']) {
                continue;
            }
            while (!answer.empty() && answer.back() > s[i] && last_idx[answer.back() - 'a'] > i) {
                is_in_ans[answer.back() - 'a'] = false;
                answer.pop_back();
            }
            answer.push_back(s[i]);
            is_in_ans[s[i] - 'a'] = true;
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1081_H
