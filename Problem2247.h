//
// Created by Fengwei Zhang on 10/10/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2247_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2247_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem2247
{
public:
    // 状态压缩DP，类似AcWig 91。
    int maximumCost(int n,
                    const vector<vector<int>>& highways,
                    int k)
    {
        if (k >= n)
            return -1;

        vector<vector<pair<int, int>>> graph(n);

        for (const auto &e : highways)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        const int &maxMask = 1 << n;

        /*
         * dp[mask][u]:
         * 已访问城市集合为 mask，
         * 当前位于城市 u 时的最大 cost
         */
        vector<vector<int>> dp(maxMask, vector<int>(n, -1));

        // 可以从任意城市出发
        for (int u = 0; u < n; ++u)
            dp[1 << u][u] = 0;

        int answer = -1;

        for (int mask = 1; mask < maxMask; ++mask)
        {
            int cityCount =
                __builtin_popcount((unsigned)mask);

            // 已经超过 k+1 个城市，不需要继续
            if (cityCount > k + 1)
                continue;

            for (int u = 0; u < n; ++u)
            {
                if (dp[mask][u] == -1)
                    continue;

                // 恰好经过 k 条 highway
                // => 恰好访问 k+1 个城市
                if (cityCount == k + 1)
                {
                    answer =
                        max(answer, dp[mask][u]);

                    continue;
                }

                for (auto [v, w] : graph[u])
                {
                    // 城市不能重复访问
                    if (mask & (1 << v))
                        continue;

                    int newMask =
                        mask | (1 << v);

                    dp[newMask][v] =
                        max(
                            dp[newMask][v],
                            dp[mask][u] + w
                        );
                }
            }
        }

        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM2247_H
