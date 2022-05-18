//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0288_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0288_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ValidWordAbbr {
    // 依据abbreviation给单词分类，存入对应的集合（set）；若此单词存在于集合，且集合大小为1，返回true
public:
    ValidWordAbbr(const vector<string> &dictionary) {
        for (const auto &w: dictionary) {
            dict[abbreviate(w)].insert(w);
        }
    }

    bool isUnique(const string &word) {
        auto a = abbreviate(word);
        return !dict.count(a) || (dict[a].count(word) && dict[a].size() == 1);
    }

private:
    unordered_map<string, unordered_set<string>> dict;

    string abbreviate(const string &s) {
        return s[0] + ((int) s.size() > 2 ? to_string((int) s.size() - 2) : "") + s[s.size() - 1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0288_H
