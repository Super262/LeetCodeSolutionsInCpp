//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0389_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0389_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(const string &s, const string &t) {
        unordered_map<char, int> counter;
        for (auto ch: t) {
            ++counter[ch];
        }
        for (auto ch: s) {
            --counter[ch];
        }
        for (auto &item: counter) {
            if (item.second) {
                return item.first;
            }
        }
        return '\0';
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0389_H
