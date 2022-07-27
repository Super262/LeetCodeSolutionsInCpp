//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0758_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0758_H

#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Problem0758 {
    // 对于任意s[i]，暴力枚举words中所有单词，验证s[i:i+k-1]是否是某个长度为k的单词；若s[i]属于某个单词，设置mask[i]=true
    // 若mask[i:j]均为true，用加粗标记包围s[i:j]
public:
    string boldWords(const vector<string> &words, const string &s) {
        bool masked[s.size()];
        memset(masked, 0, sizeof masked);
        for (int i = 0; i < s.size(); ++i) {
            for (const auto &w: words) {
                if (i + w.size() > s.size()) {
                    continue;
                }
                bool valid = true;
                for (int j = 0, k = i; j < w.size(); ++j, ++k) {
                    if (w[j] != s[k]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    continue;
                }
                for (int j = i; j < i + w.size(); ++j) {
                    masked[j] = true;
                }
            }
        }
        string ans;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (!masked[i]) {
                ans += s[i];
                continue;
            }
            ans += "<b>";
            auto j = i;
            while (j < s.size() && masked[j]) {
                ++j;
            }
            ans += s.substr(i, j - i);
            ans += "</b>";
            i = j - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0758_H
