//
// Created by Fengwei Zhang on 10/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0057_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0057_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：分段处理
    // 将intervals从左到右分成三段a、b、c：a和x无交集，b和x有交集，c和x无交集
    // 对于结果ans，a、c保持不变，将b和x合并后生成的新分段加入ans
public:
    vector<vector<int>> insert(const vector<vector<int>> &intervals, vector<int> x) {
        vector<vector<int>> result;
        int i = 0;
        while (i < (int) intervals.size() && x[0] > intervals[i][1]) {  // 左边无交集的一段
            result.emplace_back(intervals[i]);
            ++i;
        }

        // 中间有交集的一段
        if (i < (int) intervals.size()) {
            x[0] = min(x[0], intervals[i][0]);  // 注意：这里只能改动x[0]，x[1]不变（因为左边的无交集段可能不存在）
            while (i < (int) intervals.size() && x[1] >= intervals[i][0]) {
                x[1] = max(x[1], intervals[i][1]);
                ++i;
            }
        }
        result.emplace_back(x);

        while (i < (int) intervals.size()) {  // 右边无交集的一段
            result.emplace_back(intervals[i]);
            ++i;
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0057_H
