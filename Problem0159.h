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
        const int n = (int) s.size();
        int existed[256];  // 手写哈希表记录每类字符的频率，加快速度
        int dictSize = 0;  // 当前字符种类别数
        memset(existed, 0, sizeof existed);

        int r = 0;
        int l = 0;
        int result = 0;
        while (r < n) {  // 滑动窗口
            while (l < r && existed[s[r]] == 0 && dictSize >= 2) {
                --existed[s[l]];
                if (existed[s[l]] == 0) {  // 某类字符不存在了
                    --dictSize;
                }
                ++l;
            }
            if (!existed[s[r]]) {  // 新加入一类字符
                ++dictSize;
            }
            ++existed[s[r]];
            result = max(result, r - l + 1);
            ++r;
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0159_H
