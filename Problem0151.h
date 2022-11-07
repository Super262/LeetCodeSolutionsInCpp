//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0151_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0151_H

#include <string>

using namespace std;

class Problem0151 {
    // 去掉前导空格、后余空格，翻转每个单词
public:
    string reverseWords(string s) {
        int st = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            auto j = i;
            auto ed = st;
            while (j < (int) s.size() && s[j] != ' ') {
                s[ed] = s[j];
                ++ed;
                ++j;
            }
            reverse(s.begin() + st, s.begin() + ed); // 翻转单词（s[st:ed-1]）
            s[ed] = ' ';  // 添加分隔符
            st = ed;
            ++st;
            i = j;
        }
        if (st) {
            --st;
        }
        s.erase(s.begin() + st, s.end());  // 去除后余的空格
        reverse(s.begin(), s.end());
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0151_H
