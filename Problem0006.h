//
// Created by Fengwei Zhang on 10/22/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0006_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0006_H

#include <string>

using namespace std;

class Solution {
public:
    string convert(const string &s, const int &n) {
        if (n == 1) {
            return s;
        }
        string res;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += 2 * n - 2) {
                    res.push_back(s[j]);
                }
            } else {
                for (int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size(); j += 2 * n - 2, k += 2 * n - 2) {
                    if (j < s.size()) {
                        res.push_back(s[j]);
                    }
                    if (k < s.size()) {
                        res.push_back(s[k]);
                    }
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0006_H
