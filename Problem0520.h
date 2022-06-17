//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0520_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0520_H

#include <string>

using namespace std;

class Solution {
    // 遍历字符串，统计大写字母个数
public:
    bool detectCapitalUse(const string &word) {
        int upper_cnt = 0;
        for (const auto &x: word) {
            if (isupper(x)) {
                ++upper_cnt;
            }
        }
        if (upper_cnt == 0) {
            return true;
        }
        if (upper_cnt == word.size()) {
            return true;
        }
        if (upper_cnt == 1 && isupper(word[0])) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0520_H
