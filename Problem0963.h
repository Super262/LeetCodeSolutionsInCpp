//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0963_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0963_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 枚举中心点和对角线长度：https://leetcode-cn.com/problems/minimum-area-rectangle-ii/solution/zui-xiao-mian-ji-ju-xing-ii-by-leetcode/
    // 五元组(2*x, 2*y, l^2, i, j)：中点坐标是(x,y)，对角线长度是l，相关的两点的索引是i、j
    // 若边(a,b)和(c,d)是矩形的对角线，则他们长度相等、中点相等、不重合
public:
    double minAreaFreeRect(const vector<vector<int>> &points) {
        const auto n = (int) points.size();
        vector<vector<long long>> q;
        q.reserve(n * n);
        for (int i = 0; i < n; ++i) {
            auto x1 = points[i][0];
            auto y1 = points[i][1];
            for (int j = 0; j < i; ++j) {  // 枚举对角线的两点(x1,y1)和(x2,y2)，计算中点(cx/2,cy/2)
                auto x2 = points[j][0];
                auto y2 = points[j][1];
                auto cx = x1 + x2;
                auto cy = y1 + y2;
                q.push_back({cx, cy, getDist(points[i], points[j]), i, j});
            }
        }
        sort(q.begin(), q.end());  // 排序：聚集中点坐标、长度相等的对角线
        double ans = INT_MAX;
        for (int i = 0; i < q.size(); ++i) {
            auto j = i + 1;
            // 查找中点重合、对角线相等的点
            while (j < q.size() && q[i][0] == q[j][0] && q[i][1] == q[j][1] && q[i][2] == q[j][2]) {
                ++j;
            }
            for (auto a = i; a < j; ++a) {
                for (auto b = i; b < a; ++b) {
                    // 矩形的4个点
                    const auto &ai = points[q[a][3]];
                    const auto &aj = points[q[a][4]];
                    const auto &bi = points[q[b][3]];
                    const auto &bj = points[q[b][4]];
                    auto area = sqrt(getDist(ai, bi)) * sqrt(getDist(ai, bj));
                    if (area > 0) {
                        ans = min(ans, area);
                    }
                }
            }
            i = j - 1;
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }

private:
    static long long getDist(const vector<int> &a, const vector<int> &b) {
        auto dx = a[0] - b[0];
        auto dy = a[1] - b[1];
        return (long long) dx * dx + (long long) dy * dy;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0963_H
