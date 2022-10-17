//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1030_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1030_H

#include <vector>

using namespace std;

class Problem1030 {
    // 从中心搜索距离为d的点，不断扩大d，直到覆盖整个矩阵
    // 使用方向数组确定搜索顺序，类似54题（螺旋矩阵）
public:
    vector<vector<int>> allCellsDistOrder(int m, int n, int sx, int sy) {
        vector<vector<int>> ans;
        const int dx[4] = {1, 1, -1, -1};
        const int dy[4] = {1, -1, -1, 1};
        ans.reserve(m * n);
        ans.push_back({sx, sy});
        for (int d = 1; true; ++d) {  // 枚举距离
            auto x = sx - d;  // 起点坐标；起点离(sx,sy)的距离是d
            auto y = sy;
            int cnt = 0;  // 新增点的个数
            // 距离增加时，新增的点的最多有4*d个（以(sx,sy)为中心的、对角线长度为2*d的正方形的边缘）
            for (int i = 0; i < 4; ++i) {  // 遍历上述正方形的4条边
                for (int j = 0; j < d; ++j) {
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        ans.push_back({x, y});
                        ++cnt;
                    }
                    x += dx[i];
                    y += dy[i];
                }
            }
            if (!cnt) {
                break;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1030_H
