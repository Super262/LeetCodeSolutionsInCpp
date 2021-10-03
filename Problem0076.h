//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0076_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0076_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0076 {
private:
    string minWindow(const string &s, const string &t) {
        int hs[256], ht[256];
        memset(hs, 0, sizeof hs);  // 窗口的字符频率
        memset(ht, 0, sizeof ht);  // t的字符频率
        for (auto ch: t) {  // 统计t的字符频率
            ++ht[ch];
        }
        int validLength = 0;  // 当前窗口中的“有效长度”（包含所有类型的字符且相应字符频率不低于t的窗口长度）
        string result;
        for (int l = 0, r = 0; r < (int) s.size(); ++r) {
            ++hs[s[r]];
            if (hs[s[r]] <= ht[s[r]]) {  // 没有冗余字符
                ++validLength;
            }
            while (l <= r && hs[s[l]] > ht[s[l]]) {  // 删去冗余字符
                --hs[s[l]];
                ++l;
            }
            if (validLength == (int) t.size()) {
                if (result.empty() || r - l + 1 < result.size()) {
                    result = s.substr(l, r - l + 1);
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0076_H
