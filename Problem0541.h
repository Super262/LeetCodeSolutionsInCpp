//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0541_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0541_H

#include <string>

using namespace std;

class Solution {
    // 将原数组从起点分成多个长度为2*k的分段，翻转每个分段内前k个字符
    // 细节：注意防止越界
public:
    string reverseStr(string s, int k) {
        const auto n = (int) s.size();
        for (int i = 0; i < n; i += 2 * k) {
            auto l = i;
            auto r = min(l + k, n);  // 注意防止越界
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0541_H
