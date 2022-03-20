//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0345_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0345_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> towels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        auto r = (int) s.size() - 1;
        while (l < r) {
            if (towels.count(s[l]) && towels.count(s[r])) {
                swap(s[l], s[r]);
                ++l;
                --r;
                continue;
            }
            if (!towels.count(s[l])) {
                ++l;
            }
            if (!towels.count(s[r])) {
                --r;
            }
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0345_H
