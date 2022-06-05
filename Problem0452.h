//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0452_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0452_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 区间选点问题，同AcWing 905：先按照右端点对区间排序，再从左向右扫描所有区间
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 1;
        auto end = points[0][1];
        for (int i = 1; i < (int) points.size(); ++i) {
            if (points[i][0] > end) {
                ++ans;
                end = points[i][1];  // 只有发生区间合并，才更新右边界
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0452_H
