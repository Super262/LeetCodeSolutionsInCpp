//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1027_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1027_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // f[i][j]：以nums[i]结尾、公差为j的最长子序列
    // 注意，时间复杂度是O(n^2)，不是O(n^3)
public:
    int longestArithSeqLength(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int f[n][1001];
        memset(f, 0, sizeof f);
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto d = nums[i] - nums[j] + 500;
                f[i][d] = max(f[i][d], max(f[j][d], 1) + 1);
                ans = max(ans, f[i][d]);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1027_H
