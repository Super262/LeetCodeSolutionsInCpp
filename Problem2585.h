//
// Created by Fengwei Zhang on 9/10/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2585_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2585_H

#include <vector>
#include <cstring>

using namespace std;

#define PROBLEM_2585_MOD (1000000007)
class Problem2585
{
public:
    /* 完全背包问题：f[j]表示目标分数为j时的方案数 */
    int waysToReachTarget(int target, const vector<vector<int>> &types)
    {
        int *f = (int *)calloc(target + 1, sizeof(int));
        int j, k, answer;

        f[0] = 1;
        for (const vector<int> &item : types)
        {
            for (j = target; j; --j)
            {
                /* 注意：k要从1开始，否则会重复计数 */
                for (k = 1; k <= item[0] && k * item[1] <= j; ++k)
                {
                    if (f[j - k * item[1]])
                        /* 为防止溢出，取模前先转换为long */
                        f[j] = (int)((long)((f[j] + f[j - k * item[1]]) % PROBLEM_2585_MOD));
                }
            }
        }

        answer = f[target];
        free(f);
        return answer;
    }
};
#undef PROBLEM_2585_MOD
#endif // LEETCODESOLUTIONSINCPP_PROBLEM2585_H
