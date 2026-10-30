#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2684_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2684_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
LeetCode 2684 - Maximum Number of Moves in a Grid

本质：
    网格上的 DAG 最长路。

因为每一步只能从第 i-1 列走到第 i 列，
所以列本身就是天然的拓扑顺序。

--------------------------------------------------

状态定义：

    f(i, j) =
        到达 grid[j][i] 时，
        最多已经走了多少步。

当前格子 (j, i) 的前驱只能来自上一列：

    (j - 1, i - 1)
    (j,     i - 1)
    (j + 1, i - 1)

并且必须满足严格递增：

    grid[prev] < grid[j][i]

--------------------------------------------------

状态转移：

如果某个前驱可达，则：

    f(i, j) =
        max(
            f(i, j),
            f(i - 1, prevRow) + 1
        )

因为第 0 列的所有格子都可以作为起点，
起始 move 数为 0。

如果使用 0 同时表示：
    1. 第 0 列起点
    2. 不可达状态

那么从第 0 列转移到第 1 列时，
需要额外判断：

    i == 1

更干净的写法是：
    reachable 状态初始化为 -1，
    第 0 列初始化为 0，
这样可以去掉特殊判断。

--------------------------------------------------

滚动数组：

当前第 i 列只依赖第 i-1 列，
所以不需要保存完整的 m * n DP。

只保留两列：

    f[i % 2][row]

空间从：

    O(m * n)

降为：

    O(m)

--------------------------------------------------

答案：

最长路径不一定能够走到最后一列，

所以不能只在最后一列取最大值。

必须在每次计算状态时维护：

    answer = max(answer, f(i, j))

--------------------------------------------------

复杂度：

每个格子最多检查 3 个前驱。

时间：
    O(m * n)

空间：
    O(m)

核心：

    2684 可以看成 329 的简化版。

    329 的拓扑顺序需要通过数值关系确定，
    而 2684 的边只能从左往右，
    所以“列”天然就是拓扑层。

    因此直接按列做 DP 即可。
*/

class Problem2684
{
public:
    int maxMoves(const vector<vector<int>>& grid)
    {
        const int m = (int)grid.size();
        const int n = (int)grid.back().size();

        int *_f_ = (int *)calloc(m * 2, sizeof(int));

#define f(i, j) (_f_[((i) % 2) * m + (j)])

        int answer = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int t = 0;

                /*
                 * 从左上角转移：
                 * (j-1, i-1) -> (j, i)
                 */
                if (j > 0 &&
                    grid[j - 1][i - 1] < grid[j][i] &&
                    (i == 1 || f(i - 1, j - 1)))
                {
                    t = max(t, f(i - 1, j - 1) + 1);
                }

                /*
                 * 从正左方转移：
                 * (j, i-1) -> (j, i)
                 */
                if (grid[j][i - 1] < grid[j][i] &&
                    (i == 1 || f(i - 1, j)))
                {
                    t = max(t, f(i - 1, j) + 1);
                }

                /*
                 * 从左下角转移：
                 * (j+1, i-1) -> (j, i)
                 */
                if (j < m - 1 &&
                    grid[j + 1][i - 1] < grid[j][i] &&
                    (i == 1 || f(i - 1, j + 1)))
                {
                    t = max(t, f(i - 1, j + 1) + 1);
                }

                f(i, j) = t;

                answer = max(answer, t);
            }
        }

#undef f

        free(_f_);
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM2684_H
