//
// Created by Fengwei Zhang on 9/19/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1092_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1092_H

#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1092
{
public:
    /* 求最长公共子序列，然后从结果集来恢复答案 */
    string shortestCommonSupersequence(const string &s1, const string &s2)
    {
        const int &m = (int)s1.size();
        const int &n = (int)s2.size();

        /* 使用1维数组来提速；宏f(i, j)映射二维到一维 */
        int *_f_ = (int *)calloc(m * n, sizeof(int));

#define f(i, j) (_f_[(i) * n + (j)])

        /* f(i, j)：s1[0:i]和s2[0:j]最长公共子序列 */
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0, x, y; j < n; ++j)
            {
                x = i ? f(i - 1, j) : 0;
                y = j ? f(i, j - 1) : 0;

                f(i, j) = max(f(i, j), max(x, y));

                if (s1[i] == s2[j])
                {
                    if (i && j)
                        f(i, j) = max(f(i, j), f(i - 1, j - 1) + 1);
                    else
                        f(i, j) = 1;
                }
            }
        }

        /* 最长公共子序列为0，直接返回(s1 + s2) */
        if (!f(m - 1, n - 1))
        {
            free(_f_);
            return (s1 + s2);
        }

        /* 从尾部恢复答案 */
        int i = m - 1;
        int j = n - 1;
        string answer;

        answer.reserve(m + n - f(m - 1, n - 1));

        while (i >= 0 && j >= 0)
        {
            if (s1[i] == s2[j])
            {
                answer.push_back(s1[i]);
                --i;
                --j;
            }
            else
            {
                int x = i > 0 ? f(i - 1, j) : 0;
                int y = j > 0 ? f(i, j - 1) : 0;

                if (x >= y)
                {
                    answer.push_back(s1[i]);
                    --i;
                }
                else
                {
                    answer.push_back(s2[j]);
                    --j;
                }
            }
        }

        while (i >= 0)
            answer.push_back(s1[i--]);

        while (j >= 0)
            answer.push_back(s2[j--]);

        reverse(answer.begin(), answer.end());

#undef f
        free(_f_);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1092_H
