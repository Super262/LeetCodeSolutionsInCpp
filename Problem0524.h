//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0524_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0524_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLongestWord(const string &s, const vector<string> &dict) {
        int ans_idx = -1;
        for (int i = 0; i < dict.size(); ++i) {
            if (!isSubSeq(s, dict[i])) {
                continue;
            }
            if (ans_idx == -1 || dict[ans_idx].size() < dict[i].size() ||
                (dict[ans_idx].size() == dict[i].size() && dict[ans_idx] > dict[i])) {
                ans_idx = i;
            }
        }
        if (ans_idx == -1) {
            return "";
        }
        return dict[ans_idx];
    }

private:
    bool isSubSeq(const string &a, const string &b) {  // 判断b是否为a的子序列
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                ++j;
            }
            ++i;
        }
        return j >= b.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0524_H
