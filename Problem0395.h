//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0395_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0395_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 思想：枚举区间内最多包含的字符种类数（最多26），使序列具备单调性，可以采用双指针算法
    // https://www.acwing.com/solution/content/8092/
public:
    int longestSubstring(const string &s, const int &k) {
        unordered_map<char, int> counter;
        int res = 0;
        for (int t = 1; t <= 26; ++t) {
            counter.clear();
            int ch_cnt = 0;  // 字符种类数
            int valid_cnt = 0; // 字符频率不少于k的字符种类数
            for (int l = 0, r = 0; r < s.size(); ++r) {
                if (counter[s[r]] == 0) {  // 新字符
                    ++ch_cnt;
                }
                ++counter[s[r]];
                if (counter[s[r]] == k) {  // 新字符频率刚好为k
                    ++valid_cnt;
                }
                while (ch_cnt > t) {
                    if (counter[s[l]] == k) {  // 待删除字符频率刚好为k
                        --valid_cnt;
                    }
                    --counter[s[l]];
                    if (counter[s[l]] == 0) {
                        --ch_cnt;
                    }
                    ++l;
                }
                if (ch_cnt == valid_cnt) {  // 满足题意
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0395_H
