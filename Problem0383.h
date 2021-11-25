//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0383_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0383_H

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(const string &a, const string &b) {
        unordered_map<char, int> counter;
        for (const auto &ch: b) {
            ++counter[ch];
        }
        for (const auto &ch: a) {
            if (!counter.count(ch) || counter[ch] == 0) {
                return false;
            }
            --counter[ch];
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0383_H
