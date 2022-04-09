//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0885_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0885_H

#include <vector>

using namespace std;

class Solution {
    // 我们观察到在每个方向上走过的步长为[1, 1, 2, 2, 3, 3, ...]
    // 因此，相同步长走2次，然后右转90度
public:
    vector<vector<int>> spiralMatrixIII(const int rows, const int cols, int x, int y) {
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        int seg = 1;  // 当前步长
        int d = 0; // 当前方向
        vector<vector<int>> ans;
        ans.reserve(rows * cols);
        ans.push_back({x, y});
        while (ans.size() < rows * cols) {
            for (int k = 0; k < 2; ++k) {
                for (int i = 0; i < seg; ++i) {
                    x += dx[d];
                    y += dy[d];
                    if (x < 0 || x >= rows || y < 0 || y >= cols) {
                        continue;
                    }
                    ans.push_back({x, y});
                }
                d = (d + 1) % 4;
            }
            ++seg;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0885_H
