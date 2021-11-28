//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0435_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0435_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典贪心算法，理解并背诵
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= right) {
                ++res;
                right = intervals[i][1];
            }
        }
        return (int) intervals.size() - res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0435_H
