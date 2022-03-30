//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0792_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0792_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 采用类似"多路归并问题"的解决方法：记录words每个字符的指针，若匹配则后移指针
public:
    int numMatchingSubseq(const string &s, const vector<string> &words) {
        unordered_map<char, vector<pair<int, int>>> candidates;
        for (int i = 0; i < (int) words.size(); ++i) {
            auto ch = words[i][0];
            candidates[ch].emplace_back(i, 0);
        }
        int ans = 0;
        vector<pair<int, int>> buffer;
        for (const auto &ch: s) {
            for (const auto &t: candidates[ch]) {
                if (t.second + 1 == (int) words[t.first].size()) {
                    ++ans;
                } else {
                    buffer.emplace_back(t.first, t.second + 1);
                }
            }
            candidates[ch].clear();
            for (const auto &t: buffer) {
                candidates[words[t.first][t.second]].emplace_back(t);
            }
            buffer.clear();
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0792_H
