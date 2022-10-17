//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1031_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1031_H

#include <vector>

using namespace std;

class Problem1031 {
    // 前缀和（快速计算子数组的和） + 直接枚举（固定后面的，枚举前面的） + 分情况讨论（first_len在前面，或second_len在前面）
public:
    int maxSumTwoNoOverlap(const vector<int> &nums, int a, int b) {
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        return max(maxSum(prefix, n, a, b), maxSum(prefix, n, b, a));
    }

private:
    int maxSum(const int prefix[], const int n, int first_len, int second_len) {  // 前面的长度为first_len，后面的长度为second_len
        int ans = 0;
        // 第1段子数组出现在[1:i-1]，第2段数组为[i:i+second_len-1]；i后移时，我们更新第1段数组的最大值first_max
        for (int i = first_len + 1, first_max = 0; i + second_len - 1 <= n; ++i) {
            first_max = max(first_max, prefix[i - 1] - prefix[i - 1 - first_len]);
            ans = max(ans, first_max + prefix[i + second_len - 1] - prefix[i - 1]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1031_H
