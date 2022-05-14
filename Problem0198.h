//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0198_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0198_H

#include <vector>

using namespace std;

class Solution {
    // f[i][0]：不选择第i个房子；f[i][1]：选择第i个房子
public:
    int rob(const vector<int> &nums) {
        const int n = (int) nums.size();
        int f[2][2];  // 滚动数组优化
        f[0][0] = 0;
        f[0][1] = nums[0];
        for (int i = 1; i < n; ++i) {
            f[i % 2][0] = max(f[(i - 1) % 2][1], f[(i - 1) % 2][0]);
            f[i % 2][1] = f[(i - 1) % 2][0] + nums[i];
        }
        return max(f[(n - 1) % 2][0], f[(n - 1) % 2][1]);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0198_H
