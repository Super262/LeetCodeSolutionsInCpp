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
    // 理解动态规划的思路，积累经验
public:
    int numberOfArithmeticSlices(const vector<int> &nums) {
        auto n = (int) nums.size();
        vector<unordered_map<long long, int>> f(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                auto d = (long long) nums[i] - nums[k];
                auto it = f[k].find(d);
                int t = 0;
                if (it != f[k].end()) {
                    t = it->second;
                    res += t;
                }
                f[i][d] += t + 1;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0446_H
