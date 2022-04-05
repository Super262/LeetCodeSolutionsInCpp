//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0838_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0838_H

#include <string>

using namespace std;

class Solution {
    // 分情况讨论
    // left_fallen[i]：i左侧第一个被推倒的骨牌的索引
    // right_fallen[i]：i右侧第一个被推倒的骨牌的索引
    // 根据两侧骨牌被推倒的方向和力量对比，确定i的状态
public:
    string pushDominoes(string s) {
        const auto n = (int) s.size();
        int left_fallen[n];
        int right_fallen[n];
        for (int i = 0, j = -1; i < n; ++i) {
            if (s[i] != '.') {
                j = i;
            }
            left_fallen[i] = j;
        }
        for (auto i = n - 1, j = n; i >= 0; --i) {
            if (s[i] != '.') {
                j = i;
            }
            right_fallen[i] = j;
        }
        for (int i = 0; i < n; ++i) {
            char lf = left_fallen[i] != -1 ? s[left_fallen[i]] : 'L';
            char rf = right_fallen[i] != n ? s[right_fallen[i]] : 'R';
            if (lf == rf) {
                s[i] = lf;
                continue;
            }
            if (lf == 'L' && rf == 'R') {
                s[i] = '.';
                continue;
            }
            auto ld = i - left_fallen[i];
            auto rd = right_fallen[i] - i;
            if (ld > rd) {
                s[i] = 'L';
                continue;
            }
            if (ld < rd) {
                s[i] = 'R';
                continue;
            }
            if (ld == rd) {
                s[i] = '.';
                continue;
            }
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0838_H
