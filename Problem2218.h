//
// Created by Fengwei Zhang on 9/10/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2218_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2218_H

#include <vector>
#include <cstring>

using namespace std;

class Problem2218
{
public:
    /* 转化为0/1背包问题；对于任意piles[i]，
    ** 我们会从piles[i]中选出前s个物品（1<=s<=piles[i].size()），
    ** 或者完全跳过piles[i]；因此，先计算出前缀和以辅助动态规划。
    */
    int maxValueOfCoins(const vector<vector<int>> &piles, int k)
    {
        int *f = (int *)calloc(k + 1, sizeof(int));
        vector<vector<int>> prefixes = piles;

        for (vector<int> &p : prefixes)
        {
            for (int i = 1, m = (int)p.size(); i < m; ++i)
            {
                p[i] += p[i - 1];
            }
        }

        for (int i = 0, m, n = (int)prefixes.size(); i < n; ++i)
        {
            m = (int)prefixes[i].size();

            for (int j = k; j; --j)
            {
                for (int s = 0; s < m && s + 1 <= j; ++s)
                {
                    f[j] = max(f[j], f[j - s - 1] + prefixes[i][s]);
                }
            }
        }

        int answer = f[k];
        free(f);
        return answer;
    }
};
#endif // LEETCODESOLUTIONSINCPP_PROBLEM2218_H
