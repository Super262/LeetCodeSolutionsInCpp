//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0482_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0482_H

#include <string>

using namespace std;

class Solution {
    // 若S%K!=0，则第1组长度为S%K
public:
    string licenseKeyFormatting(const string &s, int k) {
        int data_len = 0;
        for (const auto &ch: s) {  // 得到有效信息的长度
            if (ch == '-') {
                continue;
            }
            ++data_len;
        }
        string res;
        int i = 0;
        for (int cnt = 0; i < s.size() && cnt < data_len % k; ++i) {  // 处理第1个分组
            if (s[i] == '-') {
                continue;
            }
            res.push_back((char) toupper(s[i]));
            ++cnt;
        }
        while (i < s.size()) {  // 处理后续分组
            if (s[i] == '-') {  // 遇到无效字符
                ++i;
                continue;
            }
            if (!res.empty()) {  // 分离新分组
                res.push_back('-');
            }
            for (int cnt = 0; cnt < k && i < s.size(); ++i) {
                if (s[i] == '-') {
                    continue;
                }
                res.push_back((char) toupper(s[i]));
                ++cnt;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0482_H
