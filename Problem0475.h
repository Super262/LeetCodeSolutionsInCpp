//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0475_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0475_H

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = INT_MAX;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (checkRadius(mid, houses, heaters)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    bool checkRadius(int r, const vector<int> &houses, const vector<int> &heaters) {
        // 两者位置存在单调性：双指针
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            while (j < heaters.size() && abs(heaters[j] - houses[i]) > r) {
                ++j;
            }
            if (j >= heaters.size()) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0475_H
