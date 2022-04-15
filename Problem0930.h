//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0930_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0930_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 前缀和 + 哈希表（数组实现，类似"两数之和"）
public:
    int numSubarraysWithSum(const vector<int> &nums, int goal) {
        const auto n = (int) nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int counter[n + 1];  // counter[i]：和为i的前缀的个数（数组只包含"0"、"1"，所以所有元素的和不超过n）
        int ans = 0;
        memset(counter, 0, sizeof counter);
        counter[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (prefix[i] >= goal) {
                ans += counter[prefix[i] - goal];
            }
            ++counter[prefix[i]];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0930_H
