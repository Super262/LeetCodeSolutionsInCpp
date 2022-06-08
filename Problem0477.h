//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0477_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0477_H

#include <vector>

using namespace std;

class Solution {
    // 如果我们暴力枚举任意两个数间的Hamming距离，程序会超时（O(n^2)）；因此，我们只关注数字x对最终结果的贡献是多少
    // 将所有数对距离的计算过程按位分离，固定第i个二进制位，统计数组中数字i位为"1"的个数ones_cnt，则第i位贡献的答案为ones_cnt*(n−ones_cnt)
public:
    int totalHammingDistance(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int ones_cnt = 0;
            for (const auto &x: nums) {
                if ((x >> i) & 1) {
                    ++ones_cnt;
                }
            }
            ans += ones_cnt * (n - ones_cnt);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0477_H
