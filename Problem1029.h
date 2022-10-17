//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1029_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1029_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1029 {
    // 贪心算法：按(cost[0] - cost[1])排序，前一半去A，后一半去B；采用交换法（反证）可得到正确性
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        sort(costs.begin(), costs.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        const auto n = (int) (costs.size() / 2);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0];
        }
        for (int i = n; i < 2 * n; ++i) {
            ans += costs[i][1];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1029_H
