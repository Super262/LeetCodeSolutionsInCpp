//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0748_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0748_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(const string &license, const vector<string> &words) {
        unordered_map<char, int> counter;
        for (const char &ch: license) {
            if (ch == ' ' || isdigit(ch)) {
                continue;
            }
            ++counter[(char) tolower(ch)];
        }
        int res = -1;
        for (int i = 0; i < (int) words.size(); ++i) {
            const auto &w = words[i];
            if (!compareWord(counter, w)) {
                continue;
            }
            if (res == -1 || words[res].size() > w.size()) {
                res = i;
            }
        }
        return res == -1 ? "" : words[res];
    }

private:
    bool compareWord(const unordered_map<char, int> &s, const string &w) {
        unordered_map<char, int> t;
        for (const auto &ch: w) {
            ++t[ch];
        }
        for (const auto &item: s) {
            if (!t.count(item.first) || t[item.first] < item.second) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0748_H
