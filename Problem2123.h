//
// Created by Fengwei Zhang on 9/8/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2123_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2123_H

#include <vector>
#include <cstring>

using namespace std;

class Problem2123
{
public:
    /*
    ** 匈牙利算法：按照(i + j)的奇偶将值为1的点分成“boys”和“girls”；
    ** 我们的答案是让这两组点间没有任何相联系的边；
    ** 先求出二分图的最大匹配；根据König定理，最小覆盖（结果）等于最大匹配
    */

    /* FLAT_I_J_N将(i, j)映射到(m + 1) * (n + 1)大小的一维空间 */
    #define FLAT_I_J_N(i, j, n) ((i + 1) * (n + 1) + 1 + j)
    int minimumOperations(const vector<vector<int>> &grid)
    {
        int result = 0;
        int m = (int)grid.size();
        int n = (int)grid.back().size();

        /* graph[x]保存所有和x相连的点 */
        vector<vector<int>> graph((m + 1) * (n + 1));

        /* matched_boy[x]是和“女孩x”相连的“男孩” */
        int *matched_boy = (int *)calloc((m + 1) * (n + 1), sizeof(int));

        /* visited_girl[x]是“女孩x”被访问的“时间戳” */
        int *visited_girl = (int *)calloc((m + 1) * (n + 1), sizeof(int));

        /* 上下左右四个方向 */
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;

                // 选择偶数点为“男孩”
                if ((i + j) & 1)
                    continue;

                for (int k = 0, x, y; k < 4; ++k)
                {
                    x = i + dx[k];
                    y = j + dy[k];

                    if (x < 0 || y < 0 || x >= m || y >= n)
                        continue;

                    if (!grid[x][y])
                        continue;

                    graph[FLAT_I_J_N(i, j, n)].emplace_back(FLAT_I_J_N(x, y, n));
                }
            }
        }

        for (int i = 0, stamp = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!grid[i][j])
                    continue;

                if ((i + j) & 1)
                    continue;

                ++stamp;
                if (dfsMatch(FLAT_I_J_N(i, j, n),
                             stamp, graph,
                             matched_boy, visited_girl))
                    ++result;
            }
        }

        free(matched_boy);
        free(visited_girl);
        return result;
    }
    #undef FLAT_I_J_N

private:
    bool dfsMatch(int x,
                  int stamp,
                  const vector<vector<int>> &graph,
                  int *matched_boy,
                  int *visited_girl)
    {
        for (int y : graph[x])
        {
            if (visited_girl[y] == stamp)
                continue;

            visited_girl[y] = stamp;
            if (!matched_boy[y] ||
                dfsMatch(matched_boy[y], stamp, graph,
                         matched_boy, visited_girl))
            {
                matched_boy[y] = x;
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM2123_H
