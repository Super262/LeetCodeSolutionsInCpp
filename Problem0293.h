//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0293_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0293_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 直接遍历，遇到"++"就翻转为"--"
public:
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> ans;
        for (int i = 1; i < (int) s.size(); ++i) {
            if (s[i - 1] != '+' || s[i] != '+') {
                continue;
            }
            s[i - 1] = '-';
            s[i] = '-';
            ans.emplace_back(s);
            s[i - 1] = '+';
            s[i] = '+';
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0293_H
