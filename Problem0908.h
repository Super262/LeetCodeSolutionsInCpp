//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0908_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0908_H

#include <vector>

using namespace std;

class Solution {
    // 最大值减|k|，最小值加|k|，两者的差值即是所需的分数
public:
    int smallestRangeI(const vector<int> &nums, int k) {
        int maximal = INT_MIN;
        int minimal = INT_MAX;
        for (const auto &x: nums) {
            maximal = max(maximal, x);
            minimal = min(minimal, x);
        }
        return max(0, (maximal - k) - (minimal + k));
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0908_H
