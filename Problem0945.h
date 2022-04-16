//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0945_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0945_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 重要结论：若原始状态下，a < b 成立，我们可以保证在结果状态下，a' < b' 也成立
    // f[i]：结果序列中索引为i的元素，f[i] = max(nums[i], f[i - 1] + 1)
    // 因此，我们把nums排序，再扫描一遍
public:
    int minIncrementForUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = -1;  // 上一位的结果
        for (const auto &x: nums) {
            auto y = max(prev + 1, x);
            ans += y - x;
            prev = y;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0945_H
