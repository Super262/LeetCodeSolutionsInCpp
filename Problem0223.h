//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0223_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0223_H

#include <algorithm>

using namespace std;

class Solution {
    // 1. A|B = A + B - A&B
    // 2. AB、CD两线段的相交部分：max(0, min(b, d) - max(a, c)
    // 3. 矩形重叠部分计算：将边投影到两坐标轴
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        auto xd = max(0, min(ax2, bx2) - max(ax1, bx1));
        auto yd = max(0, min(ay2, by2) - max(ay1, by1));
        return (int) ((long long) (ax2 - ax1) * (ay2 - ay1) + (long long) (bx2 - bx1) * (by2 - by1) -
                      (long long) xd * yd);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0223_H
