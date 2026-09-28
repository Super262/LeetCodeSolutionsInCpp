//
// Created by Fengwei Zhang on 9/27/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1349_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1349_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1349
{
/*
LeetCode 1349 - 状态压缩 DP

将每行座位编码为二进制，1 表示有人，0 表示没人。

定义：
    f[i][s] = 前 i+1 行中，第 i 行采用状态 s 时，
              最多能安排的学生数量。

合法性判断：
    1. (s | seatsBin[i]) == seatsBin[i]
       只能安排学生坐在可用座位上。

    2. (s & (s << 1)) == 0
       同一行不能有相邻学生。

    3. ((s0 | s1) & ((s0 | s1) << 1)) == 0
       相邻两行不能有斜对角冲突。
       前提是 s0、s1 各自均满足条件 2。

状态转移：
    枚举当前行状态 s1 和上一行状态 s0。
    若两者兼容：

        f[i][s1] = max(f[i][s1],
                       f[i-1][s0] + popcount(s1))

    不可达状态初始化为 -1。

优化细节：
    预处理每个状态是否包含连续的 1，
    以及每个状态中 1 的数量。

复杂度：
    时间 O(n * 4^m)
    空间 O(n * 2^m)

核心：
    将每行的座位安排压缩成一个整数，
    通过位运算判断座位冲突，再逐行进行 DP。
*/
public:

    int maxStudents(const vector<vector<char>>& seats)
    {
        int n = (int)seats.size();
        int m = (int)seats.back().size();

        /* 每行所有m个位置都有人时的二进制表示 */
        const int &PROBLEM1349_MAX_BIN = (1 << m);

        /* 每行座椅分布的二进制表示 */
        vector<int> seatsBin(n, 0);

        /* f[i][s] = 前 i+1 行中，第 i 行采用状态 s 时，最多能安排的学生数量 */
        vector<vector<int>> f(2, vector<int>(PROBLEM1349_MAX_BIN, -1));

        /* 二进制数是否含有连续的1（相邻的学生） */
        vector<bool> hasOneSeq(PROBLEM1349_MAX_BIN, false);

        /* 二进制数中1的个数 */
        vector<int> oneCount(PROBLEM1349_MAX_BIN, 0);

        for (int x = 0; x < PROBLEM1349_MAX_BIN; ++x)
        {
            hasOneSeq[x] = (x & (x << 1)) != 0;
            oneCount[x] = countOnes(x);
        }

        for (int i = 0 ; i < n; ++i)
        {
            for (int s : seats[i])
            {
                seatsBin[i] = seatsBin[i] << 1;
                if (s == '.')
                    ++seatsBin[i];
            }
        }

        for (int s = 0; s < PROBLEM1349_MAX_BIN; ++s)
        {
            if ((s | seatsBin[0]) != seatsBin[0])
                continue;
            
            if (hasOneSeq[s])
                continue;
            
            f[0][s] = oneCount[s];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int s1 = 0; s1 < PROBLEM1349_MAX_BIN; ++s1)
            {
                if ((s1 | seatsBin[i]) != seatsBin[i])
                    continue;
                
                if (hasOneSeq[s1])
                    continue;

                for (int s0 = 0; s0 < PROBLEM1349_MAX_BIN; ++s0)
                {
                    if (hasOneSeq[s0 | s1] || f[(i - 1) % 2][s0] == -1)
                        continue;
                    
                    f[i % 2][s1] = max(f[(i - 1) % 2][s0] + oneCount[s1],
                                       f[i % 2][s1]);
                }
            }
        }

        return *max_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }

private:
    int countOnes(int x)
    {
        int answer = 0;
        while (x)
        {
            x -= (x & (-x));
            ++answer;
        }
        return answer;
    }
};
/*
优化方向：

1. 只保留同行合法状态
   --------------------------------
   原来枚举所有 0 ~ (1<<m)-1。

   但包含相邻 1 的状态永远不会使用：

       (s & (s << 1)) != 0

   所以可以提前保存所有 validMasks，
   后续 DP 只枚举合法状态。

2. 预处理每一行可用的状态
   --------------------------------
   原来每次 DP 都判断：

       (s | seatsBin[i]) == seatsBin[i]

   可以提前为每一行保存所有合法 mask：

       rowValid[i]

   DP 时直接枚举 rowValid[i]。

3. 预计算状态兼容关系
   --------------------------------
   s0 和 s1 是否存在斜对角冲突，
   与具体第几行无关。

   所以提前计算：

       compatible[s1]

   保存所有可以作为 s1 上一行的 s0。

   DP 时不再重复：

       hasOneSeq[s0 | s1]

4. 使用滚动数组
   --------------------------------
   f[i][s] 只依赖 f[i-1][...]

   所以二维 DP：

       f[n][1<<m]

   可以改成：

       prev[...]
       cur[...]

   每处理完一行 swap(prev, cur)。

5. 使用 builtin popcount
   --------------------------------
   oneCount[s] 可以直接：

       __builtin_popcount(s)

   或者仍然预处理，避免 DP 中重复计算。

最终：
    原始：
        时间 O(n * 4^m)
        空间 O(n * 2^m)

    优化后：
        只枚举合法状态和兼容状态对，
        实际运行量会明显下降；

        DP 空间降到 O(2^m)。

核心优化思想：
    状态压缩 DP 不一定要枚举所有 bitmask。
    可以先过滤“合法状态”，
    再预计算“状态之间的转移关系”，
    最后用滚动数组压缩空间。
*/
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1349_H
