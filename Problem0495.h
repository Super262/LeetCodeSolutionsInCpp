//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0495_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0495_H

#include <vector>

using namespace std;

class Solution {
    // 注意：prev_end初始值为-1，因为有效时刻从0开始
public:
    int findPoisonedDuration(const vector<int> &timeSeries, int duration) {
        int result = 0;
        int prev_end = -1;
        for (const auto &x: timeSeries) {
            auto t = x + duration - 1;
            if (x > prev_end) {
                result += duration;
            } else {
                result += duration - (prev_end - x + 1);
            }
            prev_end = t;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0495_H
