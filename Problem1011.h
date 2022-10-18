//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1011_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1011_H

#include <vector>
#include <numeric>

using namespace std;

class Problem1011 {
    // 二分查找答案
public:
    int shipWithinDays(const vector<int> &weights, int days) {
        int l = 0;
        auto r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (canShipInDays(weights, days, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    bool canShipInDays(const vector<int> &weights, int days, int cap) {
        int ans = 1;
        int cur = 0;
        for (const auto &x: weights) {
            if (x > cap) {
                return false;
            }
            if (cur + x > cap) {
                cur = 0;
                ++ans;
            }
            cur += x;
        }
        return ans <= days;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1011_H
