//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0164_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0164_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：类似桶排序，设置(n-1)个桶来覆盖(min,max]，为了完整覆盖区间，每个区间都是左开右闭
    // 设每个桶的区间长度为x，(n - 1) * x <= (max - min)；这样设置x会使得x是所有可能的最大间距的最小值
    // 若所有点均匀分布，答案就是x；若存在某些点不均匀分布，这样设置x，使得最大间距只会出现在当前桶的最大值a和下个桶的最小值b之间
    // https://www.acwing.com/solution/content/19237/
public:
    int maximumGap(const vector<int> &nums) {
        const auto n = (int) nums.size();
        if (n < 2) {
            return 0;
        }
        int maximal = INT_MIN;
        int minimal = INT_MAX;
        for (const auto &x: nums) {  // 求最大值和最小值
            maximal = max(maximal, x);
            minimal = min(minimal, x);
        }
        if (maximal == minimal) {  // 特殊情况：所有元素相等
            return 0;
        }
        Range ranges[n - 1];  // n个元素间存在(n-1)个差值
        const auto x = (maximal - minimal + n - 2) / (n - 1);
        for (const auto &a: nums) {
            if (a == minimal) {  // 忽略边界值
                continue;
            }
            auto idx = (a - minimal - 1) / x;  // a应进入第idx个桶（idx>=0）
            ranges[idx].used = true;
            ranges[idx].max = max(a, ranges[idx].max);
            ranges[idx].min = min(a, ranges[idx].min);
        }
        long long result = INT_MIN;  // 涉及到INT边界值，用long long防止溢出
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
