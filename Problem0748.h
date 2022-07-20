//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0748_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0748_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Problem0748 {
    // 先统计出license中每个字符的频率counter，再将每个单词中字符的频率和counter比较，找到最短的完全词
public:
    string shortestCompletingWord(const string &license, const vector<string> &words) {
        unordered_map<char, int> counter;
        for (const char &ch: license) {
            if (ch == ' ' || isdigit(ch)) {
                continue;
            }
            ++counter[(char) tolower(ch)];
        }
        int ans = -1;
        for (int i = 0; i < (int) words.size(); ++i) {
            const auto &w = words[i];
            if (!compareWord(counter, w)) {
                continue;
            }
            if (ans == -1 || words[ans].size() > w.size()) {
                ans = i;
            }
        }
        return ans == -1 ? "" : words[ans];
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
