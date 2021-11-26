//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0401_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0401_H

#include <string>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(const int &num) {
        char str[6];
        vector<string> res;
        for (int s = 0; s < (1 << 10); ++s) {
            int cnt = 0;  // s中1的个数
            for (int i = 0; i < 10; ++i) {
                if ((s >> i) & 1) {
                    ++cnt;
                }
            }
            if (cnt != num) {
                continue;
            }
            auto hr = s >> 6;  // 小时
            auto mi = s & 63;  // 分钟
            if (hr >= 12 || mi >= 60) {
                continue;
            }
            sprintf(str, "%d:%02d", hr, mi);
            res.emplace_back(str);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0401_H
