//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0809_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0809_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 对s和word分别执行分段操作，得到的段长分别为a和b
    // a<b时：无解；
    // a>=b时：若a<2，a==b时有解；若a>2，有解
public:
    int expressiveWords(const string &s, const vector<string> &words) {
        int ans = 0;
        if (s.empty()) {  // 特殊情况
            for (const auto &w: words) {
                if (w.empty()) {
                    ++ans;
                }
            }
            return ans;
        }
        vector<pair<char, int>> segs_of_s;  // 数组保存分段信息，可以记录各分段出现的先后顺序
        for (int i = 0; i < (int) s.size(); ++i) {
            auto j = i;
            while (j < (int) s.size() && s[i] == s[j]) {
                ++j;
            }
            segs_of_s.emplace_back(s[i], j - i);
            i = j - 1;
        }
        for (const auto &w: words) {
            int cnt = 0;
            for (int i = 0; i < (int) w.size(); ++i) {
                if (cnt == (int) segs_of_s.size()) {  // 容易被遗漏的细节！
                    cnt = -1;
                    break;
                }
                if (segs_of_s[cnt].first != w[i]) {
                    break;
                }
                auto j = i;
                while (j < (int) s.size() && w[i] == w[j]) {
                    ++j;
                }
                auto a = segs_of_s[cnt].second;
                auto b = j - i;
                if (a < b) {
                    break;
                }
                if (a < 3 && a != b) {
                    break;
                }
                ++cnt;
                i = j - 1;
            }
            if (cnt == (int) segs_of_s.size()) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0809_H
