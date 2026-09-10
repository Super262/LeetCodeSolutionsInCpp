//
// Created by Fengwei Zhang on 9/10/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1449_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1449_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem1449
{
/*
最初：
    DP 直接保存最大字符串。
    思路直观，但每次转移都涉及 string copy / append / compare，
    开销较大，容易 TLE（cost最大长度可达5000）。

优化：
    最大整数首先取决于位数，所以只记录：
        dp[j] = cost 恰好为 j 时的最大位数
    转移：
        dp[j] = max(dp[j], dp[j - cost[digit]] + 1)

恢复：
    从 digit = 9 -> 1 枚举。
    若 dp[j] == dp[j - cost[digit]] + 1
    说明选择该 digit 仍属于最优解。

    优先选择更大的 digit，
    即可在“最大位数”的前提下得到最大整数。

核心：
    不要在 DP 中保存完整答案，
    只保存决定最优性的核心信息，再恢复具体方案。
*/
public:
    string largestNumber(const vector<int> &cost, int target)
    {
        int *f = (int *)malloc(sizeof(int) * (target + 1));
        string answer;

        f[0] = 0;
        for (int i = 1; i <= target; ++i)
            f[i] = -1;

        for (int i = 1, c; i <= 9; ++i)
        {
            c = cost[i - 1];
            for (int j = c; j <= target; ++j)
            {
                if (f[j - c] == -1)
                    continue;
                f[j] = max(f[j], f[j - c] + 1);
            }
        }

        if (f[target] < 0)
        {
            free(f);
            return "0";
        }

        for (int i = 9; i && target; --i)
        {
            while (target >=  cost[i - 1] &&
                   f[target] == f[target - cost[i - 1]] + 1)
            {
                answer.push_back((char)('0' + i));
                target -= cost[i - 1];
            }
        }

        free(f);
        return answer;
    }
};

// class Problem1449
// {
// public:
//     string largestNumber(const vector<int> &cost, int target)
//     {
//         int n = (int) cost.size();
//         vector<vector<string>> f(n + 1, vector<string>(target + 1, "#"));
//         string x, y;
//
//         for (int i = 0; i <= n; ++i)
//             f[i][0] = "";
//
//         for (int i = 1; i <= n; ++i)
//         {
//             for (int j = 1; j <= target; ++j)
//             {
//                 f[i][j] = f[i - 1][j];
//
//                 for (int k = 1; k * cost[i - 1] <= j; ++k)
//                 {
//                     x = f[i][j];
//                     y = f[i - 1][j - k * cost[i - 1]];
//
//                     if (y == "#")
//                         continue;
//
//                     y.append(k, (char)('0' + i));
//
//                     if (x == "#" || numStrEqual(y, x) > 0)
//                         f[i][j] = y;
//                     else
//                         f[i][j] = x;
//                 }
//             }
//         }
//
//         if (f[n][target] == "#")
//             return "0";
//           
//         string ans = f[n][target];
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
//
// private:
//     int numStrEqual(const string &x, const string &y)
//     {
//         if (x.length() > y.length())
//             return 1;
//
//         if (y.length() > x.length())
//             return -1;
//
//         for (int i = (int)x.length(), a, b; i; --i)
//         {
//             a = (x[i - 1] - '0');
//             b = (y[i - 1] - '0');
//
//             if (a > b)
//                 return 1;
//            
//             if (a < b)
//                 return -1;
//         }
//
//         return 0;
//     }
// };
#endif // LEETCODESOLUTIONSINCPP_PROBLEM1449_H
