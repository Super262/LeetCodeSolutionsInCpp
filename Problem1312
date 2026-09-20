//
// Created by Fengwei Zhang on 9/19/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1312_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1312_H

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem1312
{
public:
    /*
    ** f[i][j]：s[0:i]和s[j:n - 1]的最长公共子序列（n是s的长度）
    ** 若f[n - 1][0]为0，则s是回文；答案是n - f[n - 1][0]。
    */
    int minInsertions(const string &s)
    {
        const int &n = (int)s.size();
        int *_f_ = (int *)calloc(n * n, sizeof(int));

#define f(i, j) (_f_[(i) * n + j])

        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int x = i ? f(i - 1, j) : 0;
                int y = j < n - 1 ? f(i, j + 1) : 0;

                f(i, j) = max(f(i, j), max(x, y));

                if (s[i] == s[j])
                {
                    if (i && j < n - 1)
                        f(i, j) = max(f(i, j), f(i - 1, j + 1) + 1);
                    else
                        f(i, j) = 1;
                }
            }
        }

        int answer = n - f(n - 1, 0);

#undef f
        free(_f_);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1312_H
