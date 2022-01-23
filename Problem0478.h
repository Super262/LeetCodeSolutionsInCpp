//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0478_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0478_H

#include <vector>

using namespace std;

class Solution {
    // 保证等概率：围绕圆建立一个边长为2*r的正方形；映射圆心至(0,0)
    // 生成随机数x、y（-1 <= x <= 1，-1 <= y <= 1），随机点位置为(x*r,y*r)
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        cx = x_center;
        cy = y_center;
    }

    vector<double> randPoint() {
        double x, y;
        do {
            x = (double) random() / (double) RAND_MAX * 2 - 1;
            y = (double) random() / (double) RAND_MAX * 2 - 1;
        } while (x * x + y * y > 1);
        x = x * r + cx;
        y = y * r + cy;
        return {x, y};
    }

private:
    double r, cx, cy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0478_H
