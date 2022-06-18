//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0539_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0539_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    // 题目要求出最小的差值ans，易知最小差值ans一定产生于有序序列相邻两项之间；因此，我们将原序列排序，遍历序列，求得最小差值
    // 由于时间序列是环形的（"23:59"比"00:00"更大，但"23:59"的后继可以是"00:00"），ans也可能是首项和尾项的差值
public:
    int findMinDifference(const vector<string> &time_points) {
        const auto n = (int) time_points.size();
        int minutes[n];
        for (int i = 0; i < n; ++i) {  // 转化所有时间为从00:00开始的分钟数
            int a, b;
            sscanf(time_points[i].c_str(), "%d:%d", &a, &b);
            minutes[i] = a * 60 + b;
        }
        sort(minutes, minutes + n);  // 排序
        int ans = 25 * 60;
        for (int i = 1; i < n; ++i) {  // 计算(m[i] - m[i - 1])的最小值
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        ans = min(ans, minutes[0] + 24 * 60 - minutes[n - 1]);  // 环形时间链，特判开头和结尾
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0539_H
