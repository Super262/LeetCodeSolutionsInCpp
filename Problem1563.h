//
// Created by Fengwei Zhang on 9/21/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1563_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1563_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1563
/*
初始解法：区间 DP，O(n^3)

定义：
    f(left, right) =
        区间 [left, right] 中 Alice 能获得的最大分数。

枚举切点 mid：
    左区间 [left, mid - 1]
    右区间 [mid, right]

设：
    a = 左区间石子和
    b = 右区间石子和

转移：
    a < b：
        保留左边
        result = a + f(left, mid - 1)

    a > b：
        保留右边
        result = b + f(mid, right)

    a == b：
        可以任选一边
        result = a + max(f(left, mid - 1),
                         f(mid, right))

对所有 mid 取最大值。

使用前缀和 O(1) 求区间和。

复杂度：
    O(n^2) 个区间 × O(n) 个切点
    = O(n^3)
*/
{
public:
    int stoneGameV(const vector<int>& stoneValue)
    {
        const int &n = stoneValue.size();

        int *_f_ = (int *)malloc(sizeof(int) * (n + 1) * n);
        memset(_f_, -1, sizeof(int) * (n + 1) * n);

#define f(i, j) (_f_[(i) * n + (j)])

        for (int i = 0; i < n; ++i)
            f(1, i) = 0;

        int *prefix = (int *)malloc(sizeof(int) * (n + 1));
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];

        for (int len = 2; len <= n; ++len)
        {
            for (int left = 0; left + len - 1 < n; ++left)
            {
                int right = left + len - 1;
                for (int mid = left + 1; mid <= right; ++mid)
                {
                    int a = prefix[mid] - prefix[left];
                    int b = prefix[right + 1] - prefix[mid];
                    int result;

                    if (a < b)
                        result = a + f(mid - left, left);
                    else if (a > b)
                        result = b + f(right - mid + 1, mid);
                    else
                    {
                        result = a + max(f(mid - left, left),
                                         f(right - mid + 1, mid));
                    }

                    if (f(len, left) == -1)
                        f(len, left) = result;
                    else 
                        f(len, left) = max(f(len, left), result);
                }
            }
        }

        int answer = f(n, 0);

#undef f

        free(prefix);
        free(_f_);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1563_H
