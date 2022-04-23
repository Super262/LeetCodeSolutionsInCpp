//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1037_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1037_H

#include <vector>

using namespace std;

class Solution {
    // 若a、b、c三点共线，则由ab、ac构成的三角形面积为0，即 ab X ac == 0
public:
    bool isBoomerang(const vector<vector<int>> &points) {
        auto x1 = points[1][0] - points[0][0];
        auto y1 = points[1][1] - points[0][1];
        auto x2 = points[2][0] - points[0][0];
        auto y2 = points[2][1] - points[0][1];
        return crossProduct(x1, y1, x2, y2) != 0;
    }

private:
    static int crossProduct(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1037_H
