//
// Created by Fengwei Zhang on 10/10/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2741_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2741_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
状态压缩 DP：

f(mask, v)：
    使用 mask 中所有数字，
    且最后一个数字为 v 的排列数量。

若 u 可以与 v 相邻，则：

    f(mask, v) +=
        f(mask ^ (1 << v), u)

其中 u 必须：
    1. 位于 mask ^ (1 << v) 中
    2. nums[u] 和 nums[v] 满足整除条件

优化：

1. compatible[v] 用 bitmask 预处理所有合法前驱。
2. 用 lowbit 只枚举 mask 中实际存在的 v / u。
3. f 使用连续一维数组，减少 vector<vector> 开销。
4. 一个状态累加结束后只做一次 % MOD。
*/

class Problem2741
{
ublic:
    int specialPerm(const vector<int>& nums)
    {
        const int &MOD = 1000000007;
        const int &n = (int)nums.size();
        const int &maxMask = 1 << n;

        /*
         * compatible[v]:
         *
         * bit u == 1 表示 nums[u] 可以放在 nums[v] 前面：
         *
         * nums[u] % nums[v] == 0
         *              ||
         * nums[v] % nums[u] == 0
         *
         * 用一个 bitmask 保存所有 compatible 的 u，
         * 后续可直接与 prevMask 做 AND，得到合法前驱。
         */
        int *compatible =
            (int *)calloc(n, sizeof(int));

        /*
         * compatible 关系是对称的，
         * 所以只枚举 u < v，一次设置两个方向。
         */
        for (int v = 0; v < n; ++v)
        {
            for (int u = v + 1; u < n; ++u)
            {
                if ((nums[u] % nums[v]) &&
                    (nums[v] % nums[u]))
                {
                    continue;
                }

                compatible[v] |= 1 << u;
                compatible[u] |= 1 << v;
            }
        }

        /*
         * f(mask, v):
         *
         * 使用 mask 中的所有数字构成排列，
         * 并且最后一个数字为 nums[v] 时的方案数。
         *
         * 使用连续的一维数组：
         *
         * index = mask * n + v
         *
         * 相比 vector<vector<int>>：
         *   - 只有一次内存分配
         *   - 没有二级指针间接访问
         *   - cache locality 更好
         */
        int *_f_ =
            (int *)calloc((size_t)maxMask * n,
                          sizeof(int));

#define f(mask, v) (_f_[(mask) * n + (v)])

        /*
         * Base case：
         *
         * 排列只有 nums[i] 一个数字时，
         * 对应一种合法排列。
         */
        for (int i = 0; i < n; ++i)
            f(1 << i, i) = 1;

        /*
         * 状态转移：
         *
         * f(mask, v)
         *
         * 枚举排列中 v 前面的数字 u。
         *
         * 去掉最后一个 v：
         *
         * prevMask = mask ^ (1 << v)
         *
         * 那么：
         *
         * f(mask, v)
         *     = sum f(prevMask, u)
         *
         * 其中：
         *     u ∈ prevMask
         *     且 u 与 v compatible
         */
        for (int mask = 1; mask < maxMask; ++mask)
        {
            /*
             * 只枚举 mask 中存在的 v，
             * 避免 for (v = 0; v < n; ++v) 扫描无效 bit。
             */
            int vMask = mask;

            while (vMask)
            {
                /*
                 * lowbit：
                 * 取最右侧的 1。
                 */
                int vBit = vMask & -vMask;

                /*
                 * v = vBit 对应的 bit index。
                 */
                int v = __builtin_ctz((unsigned)vBit);

                // 删除刚处理过的 bit
                vMask &= vMask - 1;

                /*
                 * 从 mask 中删除城市 v。
                 */
                int prevMask = mask ^ vBit;

                // singleton 已经由 base case 初始化
                if (!prevMask)
                    continue;

                /*
                 * candidates 同时满足：
                 *
                 * 1. u 位于 prevMask 中
                 * 2. nums[u] 与 nums[v] compatible
                 */
                int candidates =
                    prevMask & compatible[v];

                long long tempSum = 0;

                /* 只枚举真正合法的前驱 u */
                while (candidates)
                {
                    int uBit =
                        candidates & -candidates;

                    int u =
                        __builtin_ctz((unsigned)uBit);

                    candidates &= candidates - 1;

                    tempSum += f(prevMask, u);
                    tempSum %= MOD;
                }

                f(mask, v) = (int)tempSum;
            }
        }

        /*
         * 完整 mask 下，
         * 最后一个数字可以是任意 nums[v]。
         */
        long long answer = 0;
        const int &fullMask = maxMask - 1;

        for (int v = 0; v < n; ++v)
        {
            answer += f(fullMask, v);
            answer %= MOD;
        }

#undef f

        free(_f_);
        free(compatible);

        return (int)answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM2741_H
