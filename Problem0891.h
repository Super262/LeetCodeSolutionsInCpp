//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0891_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0891_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 若数字x为子序列中的最大值，它对最终结果的贡献为x；若x为最小值，它对结果的贡献为-x
    // 对有序数组中的元素a[i]，以a[i]为最大值的子序列有2^i个（比a[i]小的数字有i个，我们可以选择或不选择任意数字）
    // 同理，以a[i]为最小值的子序列有2^(n-i-1)个
public:
    int sumSubseqWidths(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const int n = (int) nums.size();
        const int M = 1e9 + 7;
        int p[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * 2 % M;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (int) ((ans + (long long) p[i] * nums[i]) % M);
            ans = (int) ((ans - (long long) p[n - i - 1] * nums[i]) % M);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0891_H
