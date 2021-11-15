//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0242_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0242_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        unordered_map<char, int> sh;
        unordered_map<char, int> th;
        for (const auto &ch: s) {
            ++sh[ch];
        }
        for (const auto &ch: t) {
            ++th[ch];
        }
        return sh == th;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0242_H
