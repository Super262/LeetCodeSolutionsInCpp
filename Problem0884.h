//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0884_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0884_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(const string &s1, const string &s2) {
        auto s1_words = countWords(s1);
        auto s2_words = countWords(s2);
        vector<string> res;
        for (const auto &item: s1_words) {
            if (item.second == 1 && !s2_words.count(item.first)) {
                res.emplace_back(item.first);
            }
        }
        for (const auto &item: s2_words) {
            if (item.second == 1 && !s1_words.count(item.first)) {
                res.emplace_back(item.first);
            }
        }
        return res;
    }

private:
    static unordered_map<string, int> countWords(const string &s) {
        unordered_map<string, int> ans;
        for (int l = 0; l < (int) s.size(); ++l) {
            if (s[l] == ' ') {
                continue;
            }
            auto r = l;
            while (r < (int) s.size() && s[r] != ' ') {
                ++r;
            }
            ++ans[s.substr(l, r - l)];
            l = r;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0884_H
