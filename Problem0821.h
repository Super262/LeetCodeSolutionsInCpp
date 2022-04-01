//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0821_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0821_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // 双指针，2次扫描
public:
    vector<int> shortestToChar(const string &s, char ch) {
        const auto n = (int) s.size();
        vector<int> res(n, INT_MAX);
        for (int i = 0, j = -1; i < n; ++i) {
            if (s[i] == ch) {
                j = i;
            }
            if (j != -1) {
                res[i] = min(res[i], i - j);
            }
        }
        for (int i = n - 1, j = n; i >= 0; --i) {
            if (s[i] == ch) {
                j = i;
            }
            if (j != n) {
                res[i] = min(res[i], j - i);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0821_H
