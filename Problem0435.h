//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0435_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0435_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 依照右端点，从小到大排序所有区间：再从前向后遍历所有区间，统计不相交区间的个数ans
    // 经典贪心算法，理解并背诵
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 1;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return (int) intervals.size() - ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0435_H
