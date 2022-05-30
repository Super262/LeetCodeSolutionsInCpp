//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0434_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0434_H

#include <string>

using namespace std;

class Solution {
    // 双指针，以空格为分隔符统计区间数量
public:
    int countSegments(const string &s) {
        int res = 0;
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            if (s[r] != ' ') {
                ++r;
                continue;
            }
            if (l < r) {
                ++res;
            }
            l = r + 1;
            r = l;
        }
        if (l < r) {
            ++res;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0434_H
