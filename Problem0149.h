//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0149_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0149_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典算法，必须掌握
    // 选择起点points[i]，计算points[i]和其它点构成的直线穿过的点的数量
public:
    int maxPoints(const vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        int result = 1;
        unordered_map<long double, int> slope_lines;  // 指定斜率的直线覆盖的点的数量
        for (int i = 0; i < (int) points.size(); ++i) {
            int same_count = 0;  // 与points[i]重合的点的数量
            int x_line_size = 1;  // 垂直于x轴的直线覆盖的点的数量
            for (int j = i + 1; j < (int) points.size(); ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    ++same_count;
                } else if (points[j][0] == points[i][0]) {
                    ++x_line_size;
                }
            }
            for (int j = i + 1; j < (int) points.size(); ++j) {
                if (points[j][0] == points[i][0]) {
                    continue;
                }
                auto sl = (long double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                if (slope_lines.count(sl)) {
                    ++slope_lines[sl];
                } else {
                    slope_lines[sl] = 2;
                }
                result = max(result, slope_lines[sl] + same_count);
            }
            result = max(result, x_line_size);
            slope_lines.clear();
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0149_H
