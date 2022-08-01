//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0791_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0791_H

#include <string>
#include <unordered_map>

using namespace std;

class Problem0791 {
    // 正确定义比较函数，直接调用sort
public:
    string customSortString(const string &order, const string &s) {
        unordered_map<char, int> ch_idx;
        for (int i = 0; i < (int) order.size(); ++i) {
            ch_idx[order[i]] = i;
        }
        string ans = s;
        sort(ans.begin(), ans.end(), [&](char a, char b) {
            if (!ch_idx.count(a)) {
                return false;
            }
            if (!ch_idx.count(b)) {
                return true;
            }
            return ch_idx[a] < ch_idx[b];  // 不能写成"ch_idx[a] <= ch_idx[b]"，否则导致无法排序
        });
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0791_H
