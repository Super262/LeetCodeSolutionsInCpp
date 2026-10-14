//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0996_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0996_H

#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

class Problem0996
{
    /*
    ** 若我们不考虑重复的情况，即假设若排列的下标不同就是不同的排列，得到f个可行的排列，
    ** 牢记此性质：由排列转组合的经验得知，满足题意的组合的个数是f/{(a!)...(x!)}，a是数字a出现的次数
    ** f[s][i]：当前排列包含的数字是s（状态压缩），最后的数字的索引是i，合法的方案数
    */
public:
    int numSquarefulPerms(const vector<int> &nums) {
        const int &n = (int) nums.size();
        const int &maxMask = (int)(1 << n);
        int *_f_ = (int *)calloc(maxMask * n, sizeof(int));
        int *fact = (int *)malloc(sizeof(int) * (n + 1));

#define f(i, j) _f_[(i) * n + (j)]
        
        /* 预计算阶乘，以转换排列数到组合数 */
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;

        /* 初始化起点 */
        for (int i = 0; i < n; ++i)
            f(1 << i, i) = 1;

        /* 优化后的Hamilton算法：只考虑二进制表示中的“1” */
        for (int mask = 1; mask < maxMask; ++mask)
        {
            for (int vMask = mask; vMask; vMask &= (vMask - 1))
            {
                int vBit = (-vMask) & vMask;
                int prevMask = mask ^ vBit;

                if (!prevMask)
                    continue;

                int v = __builtin_ctz((unsigned int)vBit);
                
                for (int uMask = prevMask; uMask; uMask &= (uMask - 1))
                {
                    int uBit = (-uMask) & uMask;
                    int u = __builtin_ctz((unsigned int)uBit);

                    if (!isSquareful(nums[v] + nums[u]))
                        continue;
                    
                    f(mask, v) += f(prevMask, u);
                }
            }
        }

        /* 统计每个数的出现次数 */
        unordered_map<int, int> counter;
        for (const auto &x: nums)
            counter[x]++;

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += f(maxMask - 1, i);

        /* 排列数转组合数 */
        for (const auto &item: counter)
            ans /= fact[item.second];

#undef f
        
        free(fact);
        free(_f_);
        return ans;
    }

private:
    bool isSquareful(int x)
    {
        int y = (int) sqrt(x);
        return x == y * y;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0996_H
