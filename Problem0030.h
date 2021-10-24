//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0030_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0030_H

#include <vector>
#include <string>

using namespace std;

class Problem0030 {
public:
    vector<int> findSubstring(const string &s, const vector<string> &words) {
        vector<int> res;
        if (words.empty()) {
            return res;
        }
        unordered_map<string, int> wordFreq;
        for (const auto &item: words) {
            ++wordFreq[item];
        }
        const int w = (int) words[0].size();
        const int m = (int) words.size();
        for (int i = 0; i < w; ++i) {  // 枚举单词序列可能的起点位置：i % w
            unordered_map<string, int> wd;
            int cnt = 0;
            for (int j = i; j + w <= (int) s.size(); j += w) {  // 新单词的起点
                if (j - m * w >= i) {
                    auto prevW = s.substr(j - m * w, w);
                    --wd[prevW];
                    if (wd[prevW] < wordFreq[prevW]) {
                        --cnt;
                    }
                }
                auto nextW = s.substr(j, w);
                ++wd[nextW];
                if (wd[nextW] <= wordFreq[nextW]) {  // 词典中的单词出现
                    ++cnt;
                }
                if (cnt == m) {
                    res.emplace_back(j - (m - 1) * w);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0030_H
