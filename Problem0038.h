//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0038_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0038_H

#include <string>

using namespace std;

class Solution {
    // 依次迭代，从1到n-1：统计当前s中各数字出现的次数，生成新的s
public:
    string countAndSay(const int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string t;  // 生成新的s，描述当前的s
            for (int l = 0, r = l + 1; l < (int) s.size(); ++l) {
                while (r < (int) s.size() && s[l] == s[r]) {
                    ++r;
                }
                t += to_string(r - l) + s[l];
                l = r - 1;
            }
            s = t;
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0038_H
