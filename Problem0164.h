//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0164_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0164_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/19237/
    // 经典算法，直接背诵
public:
    int maximumGap(const vector<int> &nums) {
        const int n = (int) nums.size();
        if (n < 2) {
            return 0;
        }
        int maximal = INT_MIN;
        int minimal = INT_MAX;
        for (const auto &x: nums) {
            maximal = max(maximal, x);
            minimal = min(minimal, x);
        }
        if (maximal == minimal) {  // 特殊情况：所有元素相等
            return 0;
        }
        Range ranges[n - 1];  // n个元素间存在(n-1)个差值
        const auto seg = (maximal - minimal + n - 2) / (n - 1);
        for (const auto &x: nums) {
            if (x == minimal) {  // 忽略边界值
                continue;
            }
            auto idx = (x - minimal - 1) / seg;
            ranges[idx].used = true;
            ranges[idx].max = max(x, ranges[idx].max);
            ranges[idx].min = min(x, ranges[idx].min);
        }
        long long result = 0;  // 涉及到INT边界值，防止溢出
        // 若结果为(b-a)，则a是当前桶的最大值、b是下一个桶的最小值，因为a、b在数组中是相邻元素
        for (int i = 0, pre_max = minimal; i < n - 1; ++i) {
            if (!ranges[i].used) {  // 跳过空桶
                continue;
            }
            result = max(result, (long long) ranges[i].min - pre_max);
            pre_max = ranges[i].max;
        }
        return (int) result;
    }

private:
    struct Range {
        int max;
        int min;
        bool used;

        Range() {
            min = INT_MAX;
            max = INT_MIN;
            used = false;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0164_H
