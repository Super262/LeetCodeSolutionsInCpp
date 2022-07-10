//
// Created by Fengwei Zhang on 2/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0709_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0709_H

#include <string>

using namespace std;

class Solution {
    // 遍历s，跳过小写字母，将大写字母"偏移"距离d，d='a'-'A'
public:
    string toLowerCase(string s) {
        auto d = 'a' - 'A';
        for (auto &ch: s) {
            if (ch >= 'a' && ch <= 'z') {
                continue;
            }
            if (ch < 'A' || ch > 'Z') {
                continue;  // 注意排除非字母
            }
            ch = (char) (ch + d);
        }
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0709_H
