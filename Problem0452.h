//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0452_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0452_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 区间选点问题，背诵代码
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1, right = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > right) {
                ++res;
                right = points[i][1];  // 只有发生区间合并，才更新右边界
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0452_H
