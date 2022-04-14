//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0917_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0917_H

#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int i = 0, j = (int) s.size() - 1; i < j; ++i, --j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0917_H
