//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0812_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0812_H

#include <vector>
#include <cmath>

using namespace std;

class Problem0812 {
    // 向量的叉积；任选3点a、b、c，构成向量a-b、a-c，使用向量的叉积来计算三角形面积
public:
    double largestTriangleArea(const vector<vector<int>> &points) {
        double ans = 0;
        for (const auto &a: points) {
            for (const auto &b: points) {
                for (const auto &c: points) {
                    ans = max(ans,
                              ((double) abs(crossProduct(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1]))) / 2);
                }
            }
        }
        return ans;
    }

private:
    int crossProduct(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0812_H
