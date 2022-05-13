//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0149_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0149_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典算法，必须掌握：选择起点points[i]，计算points[i]和其它点构成的直线穿过的点的数量
    // 共有2种直线：斜率为k（k>=0）的直线，和x轴垂直的直线；不要忽略相互重合的点
public:
    int maxPoints(const vector<vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        int result = 1;
        unordered_map<long double, int> slope_lines;  // slope_lines[k]：斜率为k的直线覆盖的点的数量（k>=0）
        for (int i = 0; i < (int) points.size(); ++i) {
            int same_count = 0;  // 与points[i]重合的点的数量，初值为0
            int x_line_size = 1;  // 穿过points[i]、垂直于x轴的直线覆盖的点的数量，初值为1
            for (int j = i + 1; j < (int) points.size(); ++j) {  // 统计重合点、横坐标相同的点
                if (points[j][0] != points[i][0]) {
                    continue;
                }
                ++x_line_size;
                if (points[j][1] == points[i][1]) {
                    ++same_count;
                }
            }
            for (int j = i + 1; j < (int) points.size(); ++j) {  // 统计斜率为k的直线覆盖的点（k>=0）
                if (points[j][0] == points[i][0]) {  // 跳过横坐标相同的点
                    continue;
                }
                auto sl = (long double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                if (slope_lines.count(sl)) {
                    ++slope_lines[sl];
                } else {
                    slope_lines[sl] = 2;
                }
                result = max(result, slope_lines[sl] + same_count);  // 细节：不忘记重合的点
            }
            result = max(result, x_line_size);
            slope_lines.clear();
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0149_H
