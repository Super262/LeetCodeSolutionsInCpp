//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0241_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0241_H

#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
    // 切分字符串，然后直接DFS
public:
    vector<int> diffWaysToCompute(const string &s) {
        vector<string> parts;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (!isdigit(s[i])) {
                parts.emplace_back(s.substr(i, 1));
                continue;
            }
            auto j = i;
            while (j < (int) s.size() && isdigit(s[j])) {
                ++j;
            }
            parts.emplace_back(s.substr(i, j - i));
            i = j - 1;
        }
        return dfs(parts, 0, (int) parts.size() - 1);
    }

private:
    vector<int> dfs(const vector<string> &s, int st, int ed) {
        if (st == ed) {
            return {stoi(s[st])};
        }
        vector<int> ans;
        for (auto i = st + 1; i <= ed - 1; ++i) {  // 保证s[st:i-1]、s[i+1：ed]均至少为1
            if (s[i] != "*" && s[i] != "+" && s[i] != "-") {
                continue;
            }
            auto left_res = dfs(s, st, i - 1);
            auto right_res = dfs(s, i + 1, ed);
            for (const auto &x: left_res) {
                for (const auto &y: right_res) {
                    if (s[i] == "*") {
                        ans.emplace_back(x * y);
                    } else if (s[i] == "+") {
                        ans.emplace_back(x + y);
                    } else {
                        ans.emplace_back(x - y);
                    }
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0241_H
