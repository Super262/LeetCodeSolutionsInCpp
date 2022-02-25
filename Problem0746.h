
//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0746_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0746_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，直接背诵：f[i]到达索引为i的位置的最小代价
public:
    int minCostClimbingStairs(const vector<int> &cost) {
        const auto n = (int) cost.size();
        int f[3];
        f[0] = 0;
        f[1] = 0;
        for (int i = 2; i <= n; ++i) {
            f[i % 3] = min(f[(i - 1) % 3] + cost[i - 1], f[(i - 2) % 3] + cost[i - 2]);
        }
        return f[n % 3];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0746_H
