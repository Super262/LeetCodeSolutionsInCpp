//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0467_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0467_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(const string &p) {
        int res = 0;
        unordered_map<char, int> counter;
        for (int i = 0; i < p.size();) {
            auto j = i + 1;
            while (j < p.size() && (p[j] == p[j - 1] + 1 || (p[j] == 'a' && p[j - 1] == 'z'))) {
                ++j;
            }
            while (i < j) {
                counter[p[i]] = max(counter[p[i]], j - i);  // counter[p[i]]：以p[i]开头的连续子串的个数
                ++i;
            }
        }
        for (auto &item: counter) {
            res += item.second;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0467_H
