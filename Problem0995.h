
//
// Created by Fengwei Zhang on 4/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0995_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0995_H

#include <vector>

using namespace std;

class Problem0995 {
    // 一步步推导：我们发现nums[i]的最终状态，只受以[i-k+1:i]为起点的、长度为k的翻转区间的影响；举例分析，
    // 若nums[0]为0，我们必须翻转区间[0:k-1]；若nums[0]为1，我们不能翻转区间[0:k-1]，需跳过nums[0]
    // 我们可以用前缀和记录区间[i:j]被翻转的次数，来确定最终的结果；s[i]表示nums[0:i-1]内部经历了几次翻转
public:
    int minKBitFlips(vector<int> &nums, int k) {
        const auto n = (int) nums.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1];
            // 本次操作前，当前位nums[i - 1]被翻转了(s[i-1] - s[i-k])次，我们需要确定它的奇偶性（t&1）
            auto t = (s[i - 1] - s[max(0, i - k)]) & 1;
            nums[i - 1] ^= t;  // 奇数次（t=1）：翻转；偶数次（t=0）：保持
            if (nums[i - 1]) {
                continue;
            }
            // 当前位为0，我们要翻转以i-1为起点的、长度为k的区间
            if (i - 1 + k - 1 >= n) {  // 区间终点越界
                return -1;
            }
            ++s[i];
        }
        return s[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0995_H
