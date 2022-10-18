//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1000_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1000_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1000 {
    // 原始方程：f[i][j][k]，将stones[i:j]合并为k堆的最小代价，时间复杂度O(n^3 * k)
    // f[i][j][k] = min(f[i][j][k], f[i][u][k-1] + f[u+1][j][1])，区间DP
    // 在将[i:j]段合并为k堆前，[i:j]段应正好包含(j-i+1)堆石子；我们观察到，若每次合并m堆石子，堆数减少(m-1)
    // 因此，(m-1)应整除(j-i+1-k)，k=(j-i+1)%(m-1)，所以我们可以删去DP方程的第三维k，时间复杂度为O(n^3 / k)
    // https://www.acwing.com/solution/content/75892/
public:
    int mergeStones(const vector<int> &stones, int k) {
        const auto n = (int) stones.size();
        if ((n - 1) % (k - 1)) {  // 每次合并，堆数减少(k-1)，所以(k-1)应整除整体的变化量
            return -1;
        }
        int prefix[n + 1];  // 前缀和，用于快速计算合并代价
        int f[n + 1][n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
            f[i][i] = 0;  // 初始化
        }
        for (int length = 2; length <= n; ++length) {  // 区间DP
            for (int i = 1; i + length - 1 <= n; ++i) {
                auto j = i + length - 1;
                f[i][j] = 0x3f3f3f3f;
                for (auto p = i; p < j; p += k - 1) {  // 枚举分界点，每次倍增(k-1)，因为每次合并后堆数减少(k-1)
                    f[i][j] = min(f[i][j], f[i][p] + f[p + 1][j]);
                }
                if ((length - 1) % (k - 1) == 0) {  // (k-1)若整除(length-1)，结果合法，最终只有1堆石子
                    f[i][j] += prefix[j] - prefix[i - 1];
                }
            }
        }
        return f[1][n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1000_H
