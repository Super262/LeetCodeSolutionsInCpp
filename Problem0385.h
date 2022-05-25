//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0385_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0385_H

#include <string>
#include "nestedinteger.h"

using namespace std;

class Solution {
    // 设置全局索引，直接DFS
public:
    NestedInteger deserialize(const string &s) {
        int idx = 0;
        return dfs(s, idx);
    }

private:
    NestedInteger dfs(const string &s, int &idx) {
        NestedInteger res;
        if (s[idx] == '[') {
            ++idx;  // 跳过当前层左括号
            while (s[idx] != ']') {
                res.add(dfs(s, idx));
            }
            ++idx; // 跳过当前层右括号
        } else {
            int k = idx;
            while (k < s.size() && s[k] != ',' && s[k] != ']') {
                ++k;
            }
            res.setInteger(stoi(s.substr(idx, k - idx)));
            idx = k;
        }
        if (idx < s.size() && s[idx] == ',') {  // 跳过可能的分隔符
            ++idx;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0385_H
