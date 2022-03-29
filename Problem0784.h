//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0784_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0784_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(const string &s) {
        string temp;
        vector<string> ans;
        dfs(s, 0, temp, ans);
        return ans;
    }

private:
    void dfs(const string &s, int idx, string &temp, vector<string> &ans) {
        if (idx == (int) s.size()) {
            ans.emplace_back(temp);
            return;
        }
        if (isdigit(s[idx])) {
            temp += s[idx];
            dfs(s, idx + 1, temp, ans);
            temp.pop_back();
            return;
        }
        temp += (char) tolower(s[idx]);
        dfs(s, idx + 1, temp, ans);
        temp.pop_back();
        temp += (char) toupper(s[idx]);
        dfs(s, idx + 1, temp, ans);
        temp.pop_back();
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0784_H
