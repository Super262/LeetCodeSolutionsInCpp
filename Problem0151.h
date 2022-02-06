//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0151_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0151_H

#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            auto j = i;
            auto t = k;
            while (j < (int) s.size() && s[j] != ' ') {
                s[t++] = s[j++];
            }
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t;
            i = j;
        }
        if (k) {
            --k;
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0151_H
