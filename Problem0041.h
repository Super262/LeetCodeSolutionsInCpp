//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0041_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0041_H

#include <vector>

using namespace std;

class Problem0041 {
private:
    // https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/
    // 对于一个长度为 N 的数组，其中没有出现的最小正整数只能在[1,N+1]中。这是因为如果 [1,N]都出现了，那么答案是N+1，否则答案是[1,N]中没有出现的最小正整数。
    // 巧妙的映射方式！
    int firstMissingPositive(vector<int> &nums) {
        const int n = (int) nums.size();

        // 调整所有非正数为(n + 1)
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                continue;
            }
            nums[i] = n + 1;
        }

        // 若a（1 <= a <= n）在nums中出现，则设置nums[a - 1] = -1;
        // 这里采用相反数作为替代，非常巧妙
        for (int i = 0; i < n; ++i) {
            auto t = abs(nums[i]);
            if (t > n || t < 1) {
                continue;
            }
            nums[t - 1] = -abs(nums[t - 1]);
        }

        // 找到第一个满足nums[a - 1] > 0 的a（1 <= a <= n）
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0041_H
