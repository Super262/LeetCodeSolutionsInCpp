//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0424_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0424_H

#include <string>

using namespace std;

class Solution {
    // 暴力枚举 + 双指针
public:
    int characterReplacement(const string &s, const int &k) {
        int res = 0;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            for (int l = 0, r = 0, cnt = 0; r < s.size(); ++r) {  // cnt表示ch在s[i:j]的出现次数
                if (s[r] == ch) {
                    ++cnt;
                }
                while (l <= r && r - l + 1 - cnt > k) {  // 不是ch的字符的数量多于k
                    if (s[l] == ch) {
                        --cnt;
                    }
                    ++l;
                }
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0424_H
