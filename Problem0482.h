//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0482_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0482_H

#include <string>

using namespace std;

class Solution {
    // 根据题意要求，我们要将s分组；除第1组外，其余组的长度为k；设输入的有效字符数是data_len
    // 因此，第1组的长度为data_len%k或k；我们直接遍历s，保存有效字符，并添加分隔符
public:
    string licenseKeyFormatting(const string &s, int k) {
        int data_len = 0;
        for (const auto &ch: s) {  // 得到有效信息的长度
            if (ch == '-') {
                continue;
            }
            ++data_len;
        }
        string ans;
        int i = 0;
        for (int cnt = 0; i < (int) s.size() && cnt < data_len % k; ++i) {  // 处理第1个分组
            if (s[i] == '-') {
                continue;
            }
            ans += (char) toupper(s[i]);
            ++cnt;
        }
        while (i < (int) s.size()) {  // 处理后续分组
            if (s[i] == '-') {  // 遇到无效字符
                ++i;
                continue;
            }
            if (!ans.empty()) {  // 分离新分组
                ans += '-';
            }
            for (int cnt = 0; cnt < k && i < (int) s.size(); ++i) {
                if (s[i] == '-') {
                    continue;
                }
                ans += (char) toupper(s[i]);
                ++cnt;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0482_H
