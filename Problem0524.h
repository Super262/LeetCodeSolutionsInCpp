//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0524_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0524_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 对于字典中每个单词dict[i]，我们检查dict[i]是否为s的子序列；若dict[i]为s的子序列，且dict[i]比答案更优，则更新答案
public:
    string findLongestWord(const string &s, const vector<string> &dict) {
        int ans_idx = -1;
        for (int i = 0; i < (int) dict.size(); ++i) {
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
        int j = 0;
        for (int i = 0; i < (int) a.size() && j < (int) b.size(); ++i) {
            if (a[i] == b[j]) {
                ++j;
            }
        }
        return j >= (int) b.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0524_H
