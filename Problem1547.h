//
// Created by Fengwei Zhang on 9/20/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1547_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1547_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1547
{
/*
** 区间 DP：
** f[i][j] 表示切完 cuts[i] ~ cuts[j] 之间所有切点的最小代价。
** 枚举第一次切的位置 mid：
**    f[i][j] = min(f[i][mid] + f[mid][j] + cuts[j] - cuts[i])
** 当前这一刀的代价是整个区间长度，切完后左右两部分互相独立。
** 因此按区间长度从小到大计算。
*/
public:
    int minCost(int n, vector<int> &cuts)
    {
        const int &k = (int)cuts.size();
        int *newCuts = (int *)malloc(sizeof(int) * (k + 2));

        int *_f_ = (int *)malloc(sizeof(int) * (k + 2) * (k + 2));
        memset(_f_, -1, sizeof(int) * (k + 2) * (k + 2));

#define f(i, j) (_f_[(i) * (k + 2) + (j)])

        newCuts[0] = 0;
        newCuts[k + 1] = n;
        memcpy(newCuts + 1, cuts.data(), sizeof(int) * k);
        sort(newCuts, newCuts + k + 2);

        for (int i = 0; i < k + 1; ++i)
            f(i, i + 1) = 0;

        for (int length = 3; length <= k + 2; ++length)
        {
            for (int left = 0; left <= k + 2 - length; ++left)
            {
                int right = left + length - 1;
                for (int mid = left + 1; mid < right; ++mid)
                {
                    int cur = f(left, mid) + f(mid, right) +
                              newCuts[right] - newCuts[left];

                    if (f(left, right) == -1)
                        f(left, right) = cur;
                    else
                        f(left, right) = min(f(left, right), cur);
                }
            }
        }

        int answer = f(0, k + 1);

#undef f
        free(_f_);
        free(newCuts);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1547_H
