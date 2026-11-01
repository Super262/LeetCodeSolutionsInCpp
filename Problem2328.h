//
// Created by Fengwei Zhang on 11/1/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2328_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2328_H

#include <vector>
#include <cstring>

using namespace std;

/*
LeetCode 2328

严格递增关系构成 DAG：

    小 -> 大

定义：

    f[u] =
        以节点 u 作为终点的递增路径数量。

初始化：

    f[u] = 1

因为单个节点本身就是一条合法路径。

拓扑转移：

    对于 DAG 边 u -> v：

        f[v] += f[u]

使用 Kahn 拓扑排序保证：
    在处理 v 之前，
    所有能够到达 v 的前驱都已经完成转移。

当节点出队时，
f[u] 已经是最终值，
可以直接累加进最终答案。

优化：

    1. indegree 使用 uint8_t
    2. f 使用一维连续数组
    3. 数组模拟 queue，节点保存为 id = x*n+y
    4. 出队时直接累加答案，省掉最后一次扫描
    5. 用条件减法代替 % MOD

复杂度：

    时间 O(m*n)
    空间 O(m*n)
*/

class Problem2328
{
public:
    int countPaths(const vector<vector<int>>& grid)
    {
        const int m = (int)grid.size();
        const int n = (int)grid[0].size();
        const int total = m * n;
        const int MOD = 1000000007;

        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};

        /*
         * indegree[id]:
         * 当前格子的入度。
         *
         * 每个节点最多只有 4 个邻居，
         * 所以 uint8_t 足够。
         */
        uint8_t *indegree =
            (uint8_t *)calloc(total, sizeof(uint8_t));

        /*
         * f[id]:
         * 以当前格子作为终点的严格递增路径数量。
         *
         * 单独一个格子本身就是一条路径，
         * 所以初始值全部为 1。
         */
        int *f =
            (int *)malloc(total * sizeof(int));

        /*
         * 数组模拟 BFS queue。
         * 每个节点最多入队一次。
         */
        int *q =
            (int *)malloc(total * sizeof(int));

        for (int i = 0; i < total; ++i)
            f[i] = 1;

#define ID(x, y) ((x) * n + (y))

        /*
         * 建立 DAG：
         *
         * 较小值 -> 较大值
         *
         * 如果：
         *     grid[x][y] < grid[nx][ny]
         *
         * 则：
         *     (x,y) -> (nx,ny)
         *
         * 所以较大节点的 indegree + 1。
         */
        for (int x = 0; x < m; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n ||
                        grid[nx][ny] <= grid[x][y])
                    {
                        continue;
                    }

                    ++indegree[ID(nx, ny)];
                }
            }
        }

        /*
         * 所有 indegree == 0 的节点
         * 是 DAG 的拓扑起点。
         */
        int head = 0;
        int tail = 0;

        for (int x = 0; x < m; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                int id = ID(x, y);

                if (!indegree[id])
                    q[tail++] = id;
            }
        }

        int answer = 0;

        /*
         * Kahn 拓扑排序 + DAG 路径计数 DP。
         */
        while (head < tail)
        {
            int id = q[head++];

            int x = id / n;
            int y = id % n;

            /*
             * 节点出队时，
             * 所有能够到达它的前驱都已经完成转移，
             * 所以 f[id] 已经是最终值。
             *
             * 可以直接累加总答案，
             * 不需要最后再扫一遍整个矩阵。
             */
            answer += f[id];

            if (answer >= MOD)
                answer -= MOD;

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n ||
                    grid[nx][ny] <= grid[x][y])
                {
                    continue;
                }

                int nextId = ID(nx, ny);

                /*
                 * 所有以当前节点结束的递增路径，
                 * 都可以继续连接 nextId。
                 *
                 * 所以：
                 *
                 * f[next] += f[current]
                 */
                f[nextId] += f[id];

                /*
                 * f[nextId], f[id] 都 < MOD，
                 * 所以相加后 < 2 * MOD，
                 * 只需减一次。
                 */
                if (f[nextId] >= MOD)
                    f[nextId] -= MOD;

                /*
                 * 删除当前 DAG 边。
                 */
                if (--indegree[nextId] == 0)
                    q[tail++] = nextId;
            }
        }

#undef ID

        free(q);
        free(f);
        free(indegree);

        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM2328_H
