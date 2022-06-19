//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0557_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0557_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        while (r < (int) s.size()) {
            if (s[r] != ' ') {
                ++r;
                continue;
            }
            reverse(s.begin() + l, s.begin() + r);
            ++r;
            l = r;
        }
        if (r >= l) {
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0557_H
