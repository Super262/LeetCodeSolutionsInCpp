//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0495_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0495_H

#include <vector>

using namespace std;

class Solution {
    // 枚举输入序列，根据当前的终点计算答案并更新终点
    // 注意：prev_end初始值为-1，因为有效时刻从0开始
public:
    int findPoisonedDuration(const vector<int> &timeSeries, int duration) {
        int ans = 0;
        int prev_end = -1;
        for (const auto &x: timeSeries) {
            auto t = x + duration - 1;
            if (x > prev_end) {
                ans += duration;
            } else {
                ans += duration - (prev_end - x + 1);
            }
            prev_end = t;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0495_H
