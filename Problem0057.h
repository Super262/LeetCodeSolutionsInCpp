//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0057_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0057_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：分段处理
public:
    vector<vector<int>> insert(const vector<vector<int>> &intervals, vector<int> x) {
        vector<vector<int>> result;
        int k = 0;
        while (k < (int) intervals.size() && x[0] > intervals[k][1]) {  // 左边无交集的一段
            result.emplace_back(intervals[k]);
            ++k;
        }

        // 中间有交集的一段
        if (k < (int) intervals.size()) {
            x[0] = min(x[0], intervals[k][0]);  // 注意：这里只能改动x[0]，x[1]不变（因为左边的无交集段可能不存在）
            while (k < (int) intervals.size() && x[1] >= intervals[k][0]) {
                x[1] = max(x[1], intervals[k][1]);
                ++k;
            }
        }
        result.emplace_back(x);

        while (k < (int) intervals.size()) {  // 右边无交集的一段
            result.emplace_back(intervals[k]);
            ++k;
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0057_H
