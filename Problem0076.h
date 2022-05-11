//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0076_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0076_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 经典思路，直接背诵：https://www.acwing.com/solution/content/160/
    // 哈希表记录滑动窗口内的字符频率，找到所有字符时更新最小窗口长度
public:
    string minWindow(const string &s, const string &t) {
        int hs[256];  // 窗口内的字符频率
        int ht[256];  // t的字符频率
        memset(hs, 0, sizeof hs);
        memset(ht, 0, sizeof ht);
        for (auto ch: t) {  // 统计t的字符频率
            ++ht[ch];
        }
        int valid_length = 0;  // 当前窗口的“有效长度”（包含所有类型的字符且相应字符频率不低于t的窗口长度）
        int res_st = 0;  // 结果的起点
        int res_len = 0;  // 结果的长度（注意，初始值必须为0，存在一种边界情况使结果为空）
        for (int l = 0, r = 0; r < (int) s.size(); ++r) {
            ++hs[s[r]];
            if (hs[s[r]] <= ht[s[r]]) {  // 没有冗余字符
                ++valid_length;
            }
            while (l <= r && hs[s[l]] > ht[s[l]]) {  // 删去冗余字符
                --hs[s[l]];
                ++l;
            }
            if (valid_length == (int) t.size()) {
                if (!res_len || r - l + 1 < res_len) {
                    res_len = r - l + 1;
                    res_st = l;
                }
            }
        }
        return s.substr(res_st, res_len);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0076_H
