//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0478_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0478_H

#include <vector>

using namespace std;

class Solution {
    // 等概率：围绕半径为r的圆建立一个边长为2*r的正方形，映射随机点到这个正方形内部
    // 映射圆心至(0,0)；若生成的随机数是x、y（-1<=x<=1，-1<=y<=1），那么随机点位置为(x*r,y*r)
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        cx = x_center;
        cy = y_center;
    }

    vector<double> randPoint() {
        double x;
        double y;
        do {
            x = (double) random() / (double) RAND_MAX * 2 - 1;
            y = (double) random() / (double) RAND_MAX * 2 - 1;
        } while (x * x + y * y > 1);
        x = x * r + cx;
        y = y * r + cy;
        return {x, y};
    }

private:
    double r;
    double cx;
    double cy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0478_H
