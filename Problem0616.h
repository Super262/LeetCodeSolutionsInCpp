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
    // 遍历s，标记s中所有被发现的单词位置：再次遍历，添加tag
public:
    string addBoldTag(const string &s, const vector<string> &words) {
        bool masked[s.size()];
        memset(masked, 0, sizeof masked);
        for (int i = 0; i < (int) s.size(); ++i) {
            for (const auto &w: words) {
                if (i + (int) w.size() > (int) s.size()) {
                    continue;
                }
                bool valid = true;
                for (int j = 0, k = i; j < (int) w.size(); ++j, ++k) {
                    if (w[j] != s[k]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    continue;
                }
                for (int j = i; j < (int) i + w.size(); ++j) {
                    masked[j] = true;
                }
            }
        }
        string ans;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (!masked[i]) {
                ans.push_back(s[i]);
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0616_H
