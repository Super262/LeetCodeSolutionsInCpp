
//
// Created by Fengwei Zhang on 5/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0408_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0408_H

#include <string>

using namespace std;

class Solution {
    // 直接遍历，设i、j为遍历时的2个指针：若word[i]和abbr[j]均为字母，则检查两者是否相等；若abbr[j]为数字，则后移j、提取数字k，i后移k位，继续遍历
    // 若最后i、j均指向末尾，说明缩写合法
public:
    bool validWordAbbreviation(const string &word, const string &abbr) {
        int i = 0;
        int j = 0;
        while (i < (int) word.size() && j < (int) abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') {
                    return false;
                }
                if (j - 1 >= 0 && isdigit(abbr[j - 1])) {
                    return false;
                }
                auto k = j;
                auto num = 0;
                while (k < (int) abbr.size() && isdigit(abbr[k])) {
                    num = num * 10 + (abbr[k] - '0');
                    ++k;
                }
                j = k;
                i += num;
            } else {
                if (word[i] != abbr[j]) {
                    return false;
                }
                ++i;
                ++j;
            }
        }
        return i == (int) word.size() && j == (int) abbr.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0408_H
