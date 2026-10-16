//
// Created by Fengwei Zhang on 9/21/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1879_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1879_H

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

/*
状态压缩 DP。

定义：
    f[mask] =
        nums2 中 mask 对应的元素已经被使用，
        并与 nums1 的前 popcount(mask) 个元素完成匹配时，
        能得到的最小 XOR sum。

对于当前 mask：

    i = popcount(mask) - 1

表示当前需要确定 nums1[i] 与哪个 nums2[j] 匹配。

枚举 mask 中的每一个 j，
假设 nums2[j] 是最后加入当前匹配的元素：

    prevMask = mask ^ (1 << j)

则状态转移为：

    f[mask] =
        min(
            f[mask],
            f[prevMask] + (nums1[i] ^ nums2[j])
        )

初始化：
    f[0] = 0

最终答案：
    f[(1 << n) - 1]

优化：
    使用 lowbit 只枚举 mask 中实际存在的 j：

        jBit = vMask & -vMask
        vMask &= vMask - 1

    DP 只需要一维数组，因为已经匹配的 nums1 下标
    可以由 popcount(mask) 唯一确定。

复杂度：
    时间 O(n * 2^n)
    空间 O(2^n)

核心：
    mask 决定 nums2 中哪些元素已经被使用，
    popcount(mask) 同时决定当前匹配到 nums1 的哪个位置，
    因此无需额外记录 i。
*/

class Problem1879
{
public:
    int minimumXORSum(const vector<int>& nums1,
                      const vector<int>& nums2)
    {
        const int n = (int)nums1.size();
        const int maxMask = 1 << n;
        int *f = (int *)malloc(sizeof(int) * maxMask);

        memset(f, 0x3f, sizeof(int) * maxMask);
        f[0] = 0;

        for (int mask = 1; mask < maxMask; ++mask)
        {
            int i = (int)__builtin_popcount(mask) - 1;
            for (int vMask = mask; vMask; vMask &= vMask - 1)
            {
                int jBit = vMask & (-vMask);
                int j = (int)__builtin_ctz((unsigned int)jBit);
                f[mask] = min(f[mask], f[mask - jBit] + (nums1[i] ^ nums2[j]));
            }
        }

        int answer = f[maxMask - 1];
        free(f);
        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM1879_H
