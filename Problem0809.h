//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0809_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0809_H

#include <vector>
#include <string>

using namespace std;

class Problem0809 {
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
        const auto &segs_of_s = splitToSegments(s);
        for (const auto &w: words) {
            const auto &segs_of_w = splitToSegments(w);
            if (segs_of_w.size() != segs_of_s.size()) {
                continue;
            }
            bool is_valid = true;
            for (int i = 0; i < (int) segs_of_w.size(); ++i) {
                if (segs_of_w[i].first != segs_of_s[i].first) {
                    is_valid = false;
                    break;
                }
                if (segs_of_w[i].second > segs_of_s[i].second) {
                    is_valid = false;
                    break;
                }
                if (segs_of_w[i].second < segs_of_s[i].second && segs_of_s[i].second <= 2) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                ++ans;
            }
        }
        return ans;
    }

private:
    vector<pair<char, int>> splitToSegments(const string &s) {
        vector<pair<char, int>> ans;
        for (int l = 0; l < (int) s.size(); ++l) {
            auto r = l;
            while (r < (int) s.size() && s[l] == s[r]) {
                ++r;
            }
            ans.emplace_back(s[l], r - l);
            l = r - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0809_H
