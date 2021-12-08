//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0616_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0616_H

#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    string addBoldTag(const string &s, const vector<string> &words) {
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
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!masked[i]) {
                result.push_back(s[i]);
                continue;
            }
            result += "<b>";
            auto j = i;
            while (j < s.size() && masked[j]) {
                ++j;
            }
            result += s.substr(i, j - i);
            result += "</b>";
            i = j - 1;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0616_H
