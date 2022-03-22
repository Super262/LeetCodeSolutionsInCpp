//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0213_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0213_H

#include <vector>

using namespace std;

class Solution {
    // 经典DP，必须掌握
    // https://www.acwing.com/solution/content/19758/
    // f[i % 2][1]：盗取第i个时的最大获利；f[i % 2][0]：不盗取第i个时的最大获利
public:
    int rob(const vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        // 滚动数组优化
        int f[2][2];

        // Choose the first one: [0, n - 2]
        f[0][0] = 0;
        f[0][1] = nums[0];
        const auto n = (int) nums.size();
        for (int i = 1; i < n - 1; ++i) {
            f[i % 2][0] = max(f[(i - 1) % 2][0], f[(i - 1) % 2][1]);
            f[i % 2][1] = f[(i - 1) % 2][0] + nums[i];
        }
        auto result = max(f[(n - 2) % 2][0], f[(n - 2) % 2][1]);

        // Do not choose the first one: [1, n - 1]
        f[1][0] = 0;
        f[1][1] = nums[1];
        for (int i = 2; i < n; ++i) {
            f[i % 2][0] = max(f[(i - 1) % 2][0], f[(i - 1) % 2][1]);
            f[i % 2][1] = f[(i - 1) % 2][0] + nums[i];
        }
        result = max(max(f[(n - 1) % 2][0], f[(n - 1) % 2][1]), result);

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0213_H
