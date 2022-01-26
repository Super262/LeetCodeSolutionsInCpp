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
    // 先排序；别忘记，这是一个环形时间链，要特判结尾和开头的差值
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
        int res = 25 * 60;
        for (int i = 1; i < n; ++i) {  // 计算(m[i] - m[i - 1])的最小值
            res = min(res, minutes[i] - minutes[i - 1]);
        }
        res = min(res, minutes[0] + 24 * 60 - minutes[n - 1]);  // 环形时间链，特判开头和结尾
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0539_H
