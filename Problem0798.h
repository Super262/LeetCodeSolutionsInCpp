//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0798_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0798_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 区间标记：https://www.acwing.com/solution/content/2552/
public:
    int bestRotation(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int counter[n + 1];  // 差分数组，记录区间[l:r]被覆盖的次数
        memset(counter, 0, sizeof counter);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > n - 1) {
                continue;
            }
            if (nums[i] > i) {
                ++counter[i + 1];
                --counter[i + n - nums[i] + 1];
            } else {
                ++counter[0];
                --counter[i - nums[i] + 1];
                ++counter[i + 1];
                --counter[n];
            }
        }
        auto score = counter[0];
        auto ansi = 0;
        for (int i = 1; i < n; ++i) {
            counter[i] += counter[i - 1];
            if (score < counter[i]) {
                ansi = i;
                score = counter[i];
            }
        }
        return ansi;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0798_H
