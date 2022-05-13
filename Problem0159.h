//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0159_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0159_H

#include <cstring>
#include <string>

using namespace std;

class Solution {
    // 滑动窗口，经典题目
public:
    int lengthOfLongestSubstringTwoDistinct(const string &s) {
        const auto n = (int) s.size();
        int freq[256];  // 数组替代哈希表记录每类字符的频率，加快速度
        int counter = 0;  // 当前字符种类别数
        memset(freq, 0, sizeof freq);
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {  // 滑动窗口
            if (!freq[s[r]]) {  // 新加入的字符
                ++counter;
            }
            ++freq[s[r]];
            while (l <= r && counter > 2) {
                --freq[s[l]];
                if (!freq[s[l]]) {  // 某类字符不存在了
                    --counter;
                }
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0159_H
