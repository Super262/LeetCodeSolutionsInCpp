//
// Created by Fengwei Zhang on 4/2/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0828_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0828_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 从结果出发，统计每个字符s[i]对结果的贡献：找到当前字符的左边界l、右边界r
    // 当前字符s[i]所参与的、对结果有贡献的子串的个数是(i - l) * (r - i)
    // https://www.acwing.com/solution/content/623/
public:
    int uniqueLetterString(const string &s) {
        int prev_idx[26];
        memset(prev_idx, -1, sizeof prev_idx);
        const auto n = (int) s.size();
        int left_idx[n];
        for (int i = 0; i < n; ++i) {
            if (prev_idx[s[i] - 'A'] != -1) {
                left_idx[i] = prev_idx[s[i] - 'A'];
            } else {
                left_idx[i] = -1;
            }
            prev_idx[s[i] - 'A'] = i;
        }
        memset(prev_idx, -1, sizeof prev_idx);
        int right_idx[n];
        for (int i = n - 1; i >= 0; --i) {
            if (prev_idx[s[i] - 'A'] != -1) {
                right_idx[i] = prev_idx[s[i] - 'A'];
            } else {
                right_idx[i] = n;
            }
            prev_idx[s[i] - 'A'] = i;
        }
        int ans = 0;
        const int M = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (int) ((ans + (long long) (i - left_idx[i]) * (right_idx[i] - i)) % M);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0828_H
