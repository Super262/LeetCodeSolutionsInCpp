//
// Created by Fengwei Zhang on 11/7/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1344_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1344_H

#include <algorithm>

using namespace std;

class Problem1344 {
public:
    double angleClock(int hour, int minutes) {
        const int one_minute_angle = 6;
        const int one_hour_angle = 30;

        double minutes_angle = one_minute_angle * minutes;
        double hour_angle = (hour % 12 + minutes / 60.0) * one_hour_angle;

        auto diff = abs(hour_angle - minutes_angle);
        return min(diff, 360 - diff);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1344_H
