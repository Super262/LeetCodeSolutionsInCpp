//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1000_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1000_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1000
{
/*
** 区间 DP
** 关键限制：每次只能合并恰好 k 堆，因此每次操作后堆数减少 k - 1。
** 所以最终能合成 1 堆的必要条件是：(n - 1) % (k - 1) == 0
** f[i][j]：区间 [i, j] 合并到当前能达到的最少堆数的最小代价。
** 枚举分割点 mid，把区间拆成左右两部分：
**     f[i][j] = min(f[i][mid] + f[mid + 1][j])
**     mid 每次增加 k - 1。
** 只有当：(length - 1) % (k - 1) == 0
** 当前区间才能继续合成 1 堆，
** 此时再加上整个区间的石子总和。
** 核心：不能像普通区间合并那样每个区间都加区间和；
** 只有当前区间确实能够完成一次 k -> 1 合并时才加。
*/
public:
    int mergeStones(const vector<int>& stones, int k)
    {
        const int &n = (int)stones.size();

        if ((n - 1) % (k - 1))
            return -1;
        
        int *_f_ = (int *)malloc(sizeof(int) * (n + 1) * (n + 1));
        memset(_f_, -1, sizeof(int) * (n + 1) * (n + 1));

#define f(i, j) (_f_[(i) * (n + 1) + (j)])

        int *prefix = (int *)malloc(sizeof(int) * (n + 1));
        prefix[0] = 0;
        memcpy(prefix + 1, stones.data(), n * sizeof(int));

        for (int i = 1; i <= n ; ++i)
        {
            prefix[i] += prefix[i - 1];
            f(i, i) = 0;
        }

        for (int length = 2; length <= n; ++length)
        {
            for (int left = 1; left + length - 1 <= n; ++left)
            {
                int right = left + length - 1;
                int cur = -1;

                for (int mid = left; mid < right; mid += k - 1)
                {
                    if (f(left, mid) == -1 ||
                        f(mid + 1, right) == -1)
                        continue;
                    
                    if (cur == -1)
                        cur = f(left, mid) + f(mid + 1, right);
                    else
                        cur = min(cur, f(left, mid) + f(mid + 1, right));
                }

                if (cur != -1)
                {
                    if (f(left, right) == -1)
                        f(left, right) = cur;
                    else
                        f(left, right) = min(f(left, right), cur);
                }

                if ((length - 1) % (k - 1) == 0)
                    f(left, right) += prefix[right] - prefix[left - 1];
            }
        }

        int answer = f(1, n);

#undef f

        free(prefix);
        free(_f_);
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1000_H
