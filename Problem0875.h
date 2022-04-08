//
// Created by Fengwei Zhang on 4/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0875_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0875_H

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minEatingSpeed(const vector<int> &piles, int h) {
        int l = 1;
        auto r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (canFinish(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    static bool canFinish(const vector<int> &piles, int s, int h) {
        int t = 0;
        for (const auto &x: piles) {
            t += (x + s - 1) / s;  // t += ceil(x / s)
        }
        return t <= h;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0875_H
