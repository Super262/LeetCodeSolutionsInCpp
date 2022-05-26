//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0392_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0392_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
    // 双指针
public:
    bool isSubsequence(const string &s, const string &t) {
        int i = 0;
        int j = 0;
        while (i < (int) s.size() && j < (int) t.size()) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == (int) s.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0392_H
