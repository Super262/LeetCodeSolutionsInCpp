//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0017_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0017_H

class Problem0017 {
public:
    void dfs(const vector <string> &d2Str,
             const string &digits,
             const int &dIdx,
             string &temp,
             vector <string> &result) {
        if (dIdx == (int) digits.size()) {
            result.emplace_back(temp);
            return;
        }
        for (auto ch: d2Str[digits[dIdx] - '0']) {
            temp[dIdx] = ch;
            dfs(d2Str, digits, dIdx + 1, temp, result);
            temp[dIdx] = '\0';
        }
    }

    vector <string> letterCombinations(const string &digits) {
        vector <string> result;
        if (digits.empty()) {
            return result;
        }
        vector <string> d2Str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp(digits.size(), '\0');
        dfs(d2Str, digits, 0, temp, result);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0017_H
