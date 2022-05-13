//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0159_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0159_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(const string &s) {
        const auto n = (int) s.size();
        int freq[256];  // 数组替代哈希表记录每类字符的频率，加快速度
        int counter = 0;  // 当前字符种类别数
        memset(freq, 0, sizeof freq);
        int r = 0;
        int l = 0;
        int ans = 0;
        while (r < n) {  // 滑动窗口
            while (l < r && freq[s[r]] == 0 && counter >= 2) {
                --freq[s[l]];
                if (freq[s[l]] == 0) {  // 某类字符不存在了
                    --counter;
                }
                ++l;
            }
            if (!freq[s[r]]) {  // 新加入一类字符
                ++counter;
            }
            ++freq[s[r]];
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0159_H
