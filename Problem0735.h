//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0735_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0735_H

#include <vector>

using namespace std;

class Solution {
    // 经典贪心算法，直接背诵
public:
    vector<int> asteroidCollision(const vector<int> &asteroids) {
        vector<int> res;
        for (const auto &x: asteroids) {
            if (x > 0) {
                res.emplace_back(x);
                continue;
            }
            while (!res.empty() && res.back() > 0 && res.back() < -x) {
                res.pop_back();
            }
            if (!res.empty() && res.back() == -x) {
                res.pop_back();
            } else if (res.empty() || res.back() < 0) {
                res.emplace_back(x);
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0735_H
