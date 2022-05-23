//
// Created by Fengwei Zhang on 5/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0325_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0325_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 设prefix[i]是前i个数的和（i>=1），我们要找到最小的j，满足prefix[i]-prefix[j]=k（j<i）
    // 细节：用long型变量保存前缀和，防止溢出
public:
    int maxSubArrayLen(const vector<int> &nums, int k) {
        unordered_map<long, int> first_idx;  // first_idx[p]=i：满足prefix[i]=p的最小的i
        int ans = 0;
        long p = 0;
        first_idx[p] = 0;
        for (int i = 1; i <= (int) nums.size(); ++i) {
            p += nums[i - 1];
            if (first_idx.count(p - k)) {
                ans = max(i - first_idx[p - k], ans);
            }
            if (!first_idx.count(p)) {
                first_idx[p] = i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0325_H
