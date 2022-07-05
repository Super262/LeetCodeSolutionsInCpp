//
// Created by Fengwei Zhang on 7/4/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0681_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0681_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 枚举小时hh和分钟mm（0<=hh<24，0<=mm<60），找到距离t最近的时刻"hh:mm"
    // 计算两个时刻间的距离时，注意考虑"轮回"，即若时刻a小于时刻b，a在b的明天
public:
    string nextClosestTime(const string &t) {
        bool existed[10];
        memset(existed, 0, sizeof existed);
        existed[t[0] - '0'] = true;
        existed[t[1] - '0'] = true;
        existed[t[3] - '0'] = true;
        existed[t[4] - '0'] = true;
        const int th = (t[0] - '0') * 10 + (t[1] - '0');
        const int tm = (t[3] - '0') * 10 + (t[4] - '0');
        int ans_h = th;
        int ans_m = tm;
        int ans_d = INT_MAX;
        for (int h = 0; h < 24; ++h) {
            if (!existed[h / 10] || !existed[h % 10]) {
                continue;
            }
            for (int m = 0; m < 60; ++m) {
                if (!existed[m / 10] || !existed[m % 10]) {
                    continue;
                }
                if (h == th && m == tm) {
                    continue;
                }
                auto d = getDist(h, m, th, tm);
                if (d < ans_d) {
                    ans_h = h;
                    ans_m = m;
                    ans_d = d;
                }
            }
        }
        string ans(5, '0');
        ans[0] = (char) ((ans_h / 10) + '0');
        ans[1] = (char) ((ans_h % 10) + '0');
        ans[2] = ':';
        ans[3] = (char) ((ans_m / 10) + '0');
        ans[4] = (char) ((ans_m % 10) + '0');
        return ans;
    }

private:
    int getDist(int ah, int am, int bh, int bm) {  // 返回("ah:am"-"bh:bm")对应的分钟数
        if (ah > bh || (ah == bh && am >= bm)) {
            return (ah - bh) * 60 + (am - bm);
        }
        return 24 * 60 - abs((ah - bh) * 60 + (am - bm));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0681_H
