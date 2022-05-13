//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0161_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0161_H

#include <string>

using namespace std;

class Solution {
    // 注意细节和特殊情况
public:
    bool isOneEditDistance(const string &s, const string &t) {
        if (s.empty()) {  // 特殊情况：s或t为空
            return t.size() == 1;
        }
        if (t.empty()) {
            return s.size() == 1;
        }
        const int n = (int) s.size();
        const int m = (int) t.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            } else { // 分3种情况
                return s.substr(i) == t.substr(j + 1) ||  // 删掉t[j]
                       s.substr(i + 1) == t.substr(j) ||  // 删掉s[i]
                       s.substr(i + 1) == t.substr(j + 1);  // 替换s[i]/t[j]
            }
        }
        return j == m - 1 || i == n - 1;  // 特殊情况：s是t的前缀或t是s的前缀，则 size(s - t) == 1 或 size(t - s) == 1
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0161_H
