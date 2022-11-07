//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0152_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0152_H

#include <vector>

using namespace std;

class Problem0152 {
    // 由于输入可能有负数，我们既要保存最小值，也要保存最大值
    // f[i][0]：所有以nums[i]结尾的子数组的乘积的最大值
    // f[i][1]：所有以nums[i]结尾的子数组的乘积的最小值
public:
    int maxProduct(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int f[2][2];  // 滚动数组优化
        f[0][0] = nums[0]; // 初始化
        f[0][1] = nums[0];
        auto ans = f[0][0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                f[i % 2][0] = max(nums[i], f[(i - 1) % 2][0] * nums[i]);
                f[i % 2][1] = min(nums[i], f[(i - 1) % 2][1] * nums[i]);
            } else {  // 负负得正
                f[i % 2][0] = max(nums[i], f[(i - 1) % 2][1] * nums[i]);
                f[i % 2][1] = min(nums[i], f[(i - 1) % 2][0] * nums[i]);
            }
            ans = max(ans, f[i % 2][0]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0152_H
