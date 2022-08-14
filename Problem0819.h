//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0819_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0819_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Problem0819 {
    // 哈希表；直接遍历，跳过被禁止的单词
public:
    string mostCommonWord(const string &para, const vector<string> &banned) {
        unordered_set<string> banned_set(banned.begin(), banned.end());
        unordered_map<string, int> counter;
        string w;
        for (const auto &ch: para) {
            if (isalpha(ch)) {
                w += (char) tolower(ch);
                continue;
            }
            if (!w.empty()) {
                if (!banned_set.count(w)) {
                    ++counter[w];
                }
                w.clear();
            }
        }
        if (!w.empty() && !banned_set.count(w)) {
            ++counter[w];
        }
        string ans;
        int cnt = 0;
        for (const auto &item: counter) {
            if (item.second > cnt) {
                cnt = item.second;
                ans = item.first;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0819_H
