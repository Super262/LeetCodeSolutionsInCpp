//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1849_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1849_H

#include <string>

using namespace std;

class Solution {
public:
    bool splitString(const string &s) {
        for (int i = 1; i < s.size(); ++i) {
            if (dfs(i, stoull(s.substr(0, i)), s)) {
                return true;
            }
        }
        return false;
    }

private:
    bool dfs(int idx, unsigned long long prev, const string &s) {
        if (idx >= s.size()) {
            return true;
        }
        for (int i = idx; i < s.size(); ++i) {
            auto current = stoull(s.substr(idx, i - idx + 1));
            if (current < prev - 1) {
                continue;
            }
            if (current > prev - 1) {
                break;
            }
            if (current == prev - 1 && dfs(i + 1, current, s)) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1849_H
