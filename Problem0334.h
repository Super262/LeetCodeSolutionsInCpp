//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0334_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0334_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 判断LIS的长度是否至少为3
public:
    bool increasingTriplet(const vector<int> &nums) {
        if (nums.size() < 3) {
            return false;
        }
        int cur_max = 0;
        int lis_tail[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        lis_tail[0] = INT_MIN;
        for (const auto &x: nums) {
            int k = 0;
            while (k <= cur_max && lis_tail[k] < x) {
                ++k;
            }
            cur_max = max(cur_max, k);
            lis_tail[k] = min(x, lis_tail[k]);
            if (cur_max >= 3) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0334_H
