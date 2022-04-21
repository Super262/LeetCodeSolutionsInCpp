//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1005_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1005_H

#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
    // 采用桶排序的思想，找到负数、零和正数；优先将负数翻转，尽量对正数做偶数次翻转
public:
    int largestSumAfterKNegations(const vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        int minimal = INT_MAX;
        int maximal = 0;
        for (const auto &x: nums) {  // 统计频率；找到绝对值最大、最小的数字
            counter[x]++;
            minimal = min(minimal, abs(x));
            maximal = max(maximal, abs(x));
        }
        for (auto x = -maximal; x < 0 && k > 0; ++x) {  // 优先翻转负数
            if (!counter.count(x) || !counter[x]) {
                continue;
            }
            auto cnt = min(k, counter[x]);
            k -= cnt;
            counter[-x] += cnt;
            counter[x] -= cnt;
        }
        if (k % 2) {  // k为奇数，再翻转1次
            counter[-minimal]++;  // 翻转绝对值最小的数字
            counter[minimal]--;
        }
        int ans = 0;
        for (const auto &item: counter) {
            ans += item.first * item.second;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1005_H
