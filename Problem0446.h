//
// Created by Fengwei Zhang on 1/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0446_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0446_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 尽可能减少对哈希表的查询操作，避免超时
    // 理解动态规划的思路，积累经验：f[i][d]表示以nums[i]结尾的、差值为d的子序列的个数（包括长度为2的）
    // https://www.acwing.com/solution/content/4589/
public:
    int numberOfArithmeticSlices(const vector<int> &nums) {
        const auto n = (int) nums.size();
        vector<unordered_map<long long, int>> f(n);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto d = (long long) nums[i] - nums[j];
                auto it = f[j].find(d);
                int t = 0;
                if (it != f[j].end()) {
                    t = it->second;
                }
                f[i][d] += t + 1;
                ans += t + 1;
            }
        }
        ans -= n * (n - 1) / 2;  // 减去长度为2的子序列
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0446_H
