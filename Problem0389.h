//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0389_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0389_H

#include <string>

using namespace std;

class Solution {
    // 异或操作，相同的字符被除去
public:
    char findTheDifference(const string &s, const string &t) {
        int x = 0;
        for (auto ch: s) {
            x ^= ch;
        }
        for (auto ch: t) {
            x ^= ch;
        }
        return (char) x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0389_H
