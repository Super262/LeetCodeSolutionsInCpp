//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0436_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0436_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 数值最接近，和位置无关，不用单调栈
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        const auto n = (int) intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals[i].emplace_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> res(n, -1);
        for (const auto &x: intervals) {
            int l = 0;
            int r = n - 1;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (intervals[mid][0] >= x[1]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (intervals[r][0] >= x[1]) {
                res[x[2]] = intervals[r][2];
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0436_H
