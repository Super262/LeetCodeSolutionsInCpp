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
        string answer;
        bool isInAns[26];
        int lastIdx[26];
        memset(isInAns, 0, sizeof isInAns);
        memset(lastIdx, -1, sizeof lastIdx);
        for (int i = 0; i < (int) s.size(); ++i) {
            lastIdx[s[i] - 'a'] = i;
        }
        for (int i = 0; i < (int) s.size(); ++i) {
            if (isInAns[s[i] - 'a']) {
                continue;
            }
            while (!answer.empty() && answer.back() > s[i] && lastIdx[answer.back() - 'a'] > i) {
                isInAns[answer.back() - 'a'] = false;
                answer.pop_back();
            }
            answer.push_back(s[i]);
            isInAns[s[i] - 'a'] = true;
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1081_H
