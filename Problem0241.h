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
public:
    vector<int> diffWaysToCompute(const string &s) {
        vector<string> parts; // 预处理：切分字符串
        for (int i = 0; i < (int) s.size(); ++i) {
            if (isdigit(s[i])) {
                int j = i;
                while (j < (int) s.size() && isdigit(s[j])) {
                    ++j;
                }
                parts.emplace_back(s.substr(i, j));
                i = j - 1;
            } else {
                parts.emplace_back(s.substr(i, 1));
            }
        }
        return dfs(parts, 0, (int) parts.size() - 1);
    }

private:
    vector<int> dfs(const vector<string> &parts, const int &st, const int &ed) {
        vector<int> res;
        if (st > ed) {
            return res;
        }
        if (st == ed) {
            res.emplace_back(stoi(parts[st]));
            return res;
        }
        for (int i = st; i <= ed; ++i) {
            if (parts[i] != "+" && parts[i] != "-" && parts[i] != "*") {
                continue;
            }
            auto leftRes = dfs(parts, st, i - 1);
            auto rightRes = dfs(parts, i + 1, ed);
            for (const auto &x: leftRes) {
                for (const auto &y: rightRes) {
                    if (parts[i] == "+") {
                        res.emplace_back(x + y);
                    } else if (parts[i] == "-") {
                        res.emplace_back(x - y);
                    } else {
                        res.emplace_back(x * y);
                    }
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0241_H
