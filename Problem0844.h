//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0844_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0844_H

#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(const string &s, const string &t) {
        return removeBackspace(s) == removeBackspace(t);
    }

private:
    string removeBackspace(const string &s) {
        string ans;
        for (const auto &ch: s) {
            if (ch == '#') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
                continue;
            }
            ans += ch;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0844_H
