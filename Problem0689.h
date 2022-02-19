//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0689_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0689_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 经典DP，必须掌握
    // f[i][j]：在前i个数中找出j个长度为k的、和最大的无重叠子数组（共j*k项）的方案（i>=0,j>=1）
    // f[i][j] = max(f[i + 1][j], s[i + k - 1] - s[i - 1] + f[i + k][j - 1])，s是前缀和
    // 因此，我们需要从后向前枚举子数组起点i，同时保证字典序最小
public:
    vector<int> maxSumOfThreeSubarrays(const vector<int> &nums, const int k) {
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int f[n + 2][4];
        memset(f, 0, sizeof f);
        for (int i = n - k; i >= 0; --i) {
            for (int j = 1; j <= 3; ++j) {
                f[i][j] = max(f[i + 1][j], f[i + k][j - 1] + prefix[i + k] - prefix[i]);
            }
        }
        vector<int> res;
        int counter = 3;
        int current = 0;
        while (counter) {
            while (f[current][counter] != prefix[current + k] - prefix[current] + f[current + k][counter - 1]) {
                ++current;
            }
            res.emplace_back(current);
            --counter;
            current += k;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0689_H
