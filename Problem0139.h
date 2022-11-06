//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0139_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0139_H

#include <string>
#include <unordered_set>
#include <vector>
#include <cstring>

using namespace std;

class Problem0139 {
    // f[i]：前i个字符是否可被分割（1<=i<=n）
    // 优化查找速度：字符串哈希替代哈希表
public:
    bool wordBreak(const string &s, const vector<string> &words) {
        unordered_set<string> dict(words.begin(), words.end());
        const int n = (int) s.size();
        bool f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = true;
        for (int r = 1; r <= n; ++r) {
            for (int l = 1; l <= r; ++l) {
                f[r] = f[r] || (f[l - 1] && dict.count(s.substr(l - 1, r - l + 1)));
                if (f[r]) {
                    break;
                }
            }
        }
        return f[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0139_H
