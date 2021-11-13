//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0186_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0186_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char> &s) {
        int l = 0;
        int r = 0;
        while (r < (int) s.size()) {
            if (s[r] == ' ') {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
            ++r;
        }
        if (l < r) {
            reverse(s.begin() + l, s.begin() + r);
        }
        reverse(s.begin(), s.end());
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0186_H
