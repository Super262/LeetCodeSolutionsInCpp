//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0017_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0017_H

#include <vector>
#include <string>

using namespace std;

class Problem0017 {
public:
    vector<string> letterCombinations(const string &digits) {
        if (digits.empty()) {
            return {};
        }
        string d_to_s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp(digits.size(), '\0');
        vector<string> result;
        dfs(d_to_s, digits, 0, temp, result);
        return result;
    }

private:
    static void dfs(const string d_to_s[],
                    const string &digits,
                    const int &d_idx,
                    string &temp,
                    vector<string> &result) {
        if (d_idx == (int) digits.size()) {
            result.emplace_back(temp);
            return;
        }
        for (auto ch: d_to_s[digits[d_idx] - '0']) {
            temp[d_idx] = ch;
            dfs(d_to_s, digits, d_idx + 1, temp, result);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0017_H
