//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0500_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0500_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 对任意字符ch，记录它的行号ch_to_idx[ch]；遍历words中每个单词w的所有字符，检查它们的行号是否一致
public:
    vector<string> findWords(const vector<string> &words) {
        string lines[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> ch_to_idx;
        for (int idx = 0; idx < 3; ++idx) {
            for (const auto &ch: lines[idx]) {
                ch_to_idx[ch] = idx;
            }
        }
        vector<string> res;
        for (const auto &w: words) {
            auto t = ch_to_idx[(char) tolower(w[0])];
            bool selected = true;
            for (const auto &ch: w) {
                if (ch_to_idx[(char) tolower(ch)] != t) {
                    selected = false;
                    break;
                }
            }
            if (selected) {
                res.emplace_back(w);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0500_H
