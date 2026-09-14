//
// Created by Fengwei Zhang on 9/14/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1463_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1463_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1463
{
public:
    /* f[row1][col1][row2][col2]：
    ** Robot1起点为(row1, col1)、Robot2起点为(row2, col2)时
    ** 采集到的樱桃的最大值。当Robot1移动到下一行时，Robot2也应移动到下一行，
    ** 所以我们简化f为f[row][col1][col2]。为避免递归，我们的实现采用bottom-up思想，
    ** 即按照f[m - 1][...][...]到f[0][...][...]的顺序计算出f[0][0][n - 1]。
    ** 实现后，我们发现可以用滚动数组f[2][...][...]替代f[...][...][...]。
    ** 需要注意的是，f[i][j][j]并不是非法情况，因为grid[i][j]处的果实会被任一机器人采集。
    */
    int cherryPickup(const vector<vector<int>> &grid)
    {
        int m = (int) grid.size();
        int n = (int) grid.back().size();
        int *f[2];

        f[0] = (int *)malloc(sizeof(int) * n * n);
        f[1] = (int *)malloc(sizeof(int) * n * n);

        /* -1表示非法情况 */
        memset(f[0], -1, sizeof(int) * n * n);
        memset(f[1], -1, sizeof(int) * n * n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                /* 两机器人访问一点，不是非法情况（-1），但也不要重复采集 */
                if (j == i)
                {
                    f[(m - 1) % 2][i * n + j]
                        = grid[m - 1][i];
                }
                else
                {
                    f[(m - 1) % 2][i * n + j]
                        = grid[m - 1][i] + grid[m - 1][j];
                }
            }
        }

        for (int r = m - 2; r >= 0; --r)
        {
            for (int c1 = 0; c1 < n; ++c1)
            {
                for (int c2 = 0; c2 < n; ++c2)
                {
                    for (int y1 = -1; y1 <= 1; ++y1)
                    {
                        int t1 = c1 + y1;

                        if (t1 < 0 || t1 >= n)
                            continue;

                        for (int y2 = -1; y2 <= 1; ++y2)
                        {
                            int t2 = c2 + y2;

                            if (t2 < 0 ||
                                t2 >= n ||
                                f[(r + 1) % 2][t1 * n + t2] == -1)
                                continue;

                            /* 两机器人访问一点，不是非法情况（-1），但也不要重复采集 */
                            if (c1 == c2)
                            {
                                if (f[r % 2][c1 * n + c2] == -1)
                                {
                                    f[r % 2][c1 * n + c2] =
                                        grid[r][c1] +
                                        f[(r + 1) % 2][t1 * n + t2];
                                }
                                else
                                {
                                    f[r % 2][c1 * n + c2] =
                                        max(f[r % 2][c1 * n + c2],
                                            grid[r][c1] +
                                            f[(r + 1) % 2][t1 * n + t2]);
                                }
                            }
                            else
                            {
                                if (f[r % 2][c1 * n + c2] == -1)
                                {
                                    f[r % 2][c1 * n + c2] =
                                        grid[r][c1] + grid[r][c2] +
                                        f[(r + 1) % 2][t1 * n + t2];
                                }
                                else
                                {
                                    f[r % 2][c1 * n + c2] =
                                        max(f[r % 2][c1 * n + c2],
                                            grid[r][c1] + grid[r][c2] +
                                            f[(r + 1) % 2][t1 * n + t2]);
                                }
                            }
                        }
                    }
                }
            }
        }

        int answer = f[0][n - 1];

        free(f[0]);
        free(f[1]);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1463_H
