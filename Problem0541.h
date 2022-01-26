//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0541_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0541_H

#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        const auto n = (int) s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int l = i, r = min(i + k, n);
            reverse(s.begin() + l, s.begin() + r);  // 注意防止越界
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0541_H
