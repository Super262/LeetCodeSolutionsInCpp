//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0983_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0983_H

#include <vector>

using namespace std;

class Solution {
    // 序列DP：f[i]游览到days[i-1]天的最小花费
public:
    int mincostTickets(const vector<int> &days, const vector<int> &costs) {
        const auto n = (int) days.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1, p1 = 0, p7 = 0, p30 = 0; i <= n; ++i) {
            while (days[i - 1] - days[p1] >= 1) {
                ++p1;
            }
            while (days[i - 1] - days[p7] >= 7) {
                ++p7;
            }
            while (days[i - 1] - days[p30] >= 30) {
                ++p30;
            }
            f[i] = min(f[p1] + costs[0], min(f[p7] + costs[1], f[p30] + costs[2]));
        }
        return f[n];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0983_H
