//
// Created by Fengwei Zhang on 6/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0469_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0469_H

#include <vector>

using namespace std;

class Solution {
    // 假设当前连续的三个顶点分别是a、b、c，计算向量ab和ac的叉乘；如果结果大于0，则表示c点在向量ab的左侧，多边形的顶点是逆时针序列
    // 然后再依次计算下个顶点前后所组成向量的叉乘，如果在计算时，发生符号翻转，则此多边形是凹多边形
    // 如果所有顶点计算完毕，其结果都是正/负数，则多边形是凸多边形
public:
    bool isConvex(const vector<vector<int>> &points) {
        const auto n = (int) points.size();
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            auto cur = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
            if (!cur) {
                continue;
            }
            if ((long long) cur * prev < 0) {
                return false;
            }
            prev = cur;
        }
        return true;
    }

private:
    int crossProduct(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        auto x1 = b[0] - a[0];
        auto y1 = b[1] - a[1];
        auto x2 = c[0] - a[0];
        auto y2 = c[1] - a[1];
        return x1 * y2 - x2 * y1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0469_H
