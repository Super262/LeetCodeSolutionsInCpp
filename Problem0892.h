//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0892_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0892_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/768/
    // 逐一枚举每个非 0 的格子，上下两面对答案的贡献总共为 2；
    // 然后再遍历这个格子周围的 4 个格子，对于每个方向，假设高度为 h，则对答案的贡献为 max(0, grid[i][j] - h)；
    // 若这个格子在边界，则在边界的面上直接加上 grid[i][j] 即可。其原理就是除去挡住的部分。
public:
    int surfaceArea(vector<vector<int>> &grid) {
        const auto n = (int) grid.size();
        const int dx[4] = {0, -1, 0, 1};
        const int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (!grid[x][y]) {
                    continue;
                }
                ans += 2;
                for (int i = 0; i < 4; ++i) {
                    auto nx = x + dx[i];
                    auto ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        ans += grid[x][y];
                    } else {
                        ans += max(0, grid[x][y] - grid[nx][ny]);
                    }
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0892_H
