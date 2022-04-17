//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0953_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0953_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 逐个比较相邻单词a、b，判断它们是否满足a <= b
public:
    bool isAlienSorted(const vector<string> &words, const string &order) {
        unordered_map<char, int> ch_idx;
        for (int i = 0; i < (int) order.size(); ++i) {
            ch_idx[order[i]] = i;
        }
        for (int i = 1; i < (int) words.size(); ++i) {
            const auto &a = words[i - 1];
            const auto &b = words[i];
            int j = 0;
            while (j < (int) a.size() && j < (int) b.size()) {
                if (ch_idx[a[j]] > ch_idx[b[j]]) {
                    return false;
                }
                if (ch_idx[a[j]] < ch_idx[b[j]]) {
                    break;
                }
                ++j;
            }
            if (j < (int) a.size() && j == (int) b.size()) {  // 除去满足升序的部分，a比b长，不合法
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0953_H
