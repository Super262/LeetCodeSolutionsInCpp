//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0385_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0385_H

#include <string>

using namespace std;


class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
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
