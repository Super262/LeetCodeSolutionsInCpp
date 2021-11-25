//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0387_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0387_H

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(const string &s) {
        unordered_map<char, int> counter;
        for (auto ch: s) {
            ++counter[ch];
        }
        for (int i = 0; i < (int) s.size(); ++i) {
            if (counter[s[i]] > 1) {
                continue;
            }
            return i;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0387_H
