//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0058_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0058_H

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const string &s) {
        for (int i = (int) s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                continue;
            }
            auto j = i;
            while (j >= 0 && s[j] != ' ') {
                --j;
            }
            return i - j;
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0058_H
