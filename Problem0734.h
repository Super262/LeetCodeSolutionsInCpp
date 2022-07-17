//
// Created by Fengwei Zhang on 7/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0734_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0734_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Problem0734 {
    // 利用映射+集合保存和w相似的所有单词similarWord[w]
public:
    bool areSentencesSimilar(const vector<string> &s1, const vector<string> &s2,
                             const vector<vector<string>> &similarPairs) {
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> similarWord;
        for (const auto &p: similarPairs) {
            similarWord[p[0]].emplace(p[1]);
            similarWord[p[1]].emplace(p[0]);
        }
        for (int i = 0; i < (int) s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (similarWord.count(s2[i]) && similarWord[s2[i]].count(s1[i])) {
                continue;
            }
            if (similarWord.count(s1[i]) && similarWord[s1[i]].count(s2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0734_H
