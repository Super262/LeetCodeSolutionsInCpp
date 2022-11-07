//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0560_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0560_H

#include <vector>
#include <unordered_map>

using namespace std;

class Problem0560 {
    // 前缀和+哈希表，固定索引i，查找索引j的个数，满足prefix[i]-prefix[j]=k
public:
    int subarraySum(const vector<int> &nums, int k) {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> prefix_cnt;
        prefix_cnt[0] = 1;
        for (const auto &x: nums) {
            prefix += x;
            if (prefix_cnt[prefix - k]) {
                ans += prefix_cnt[prefix - k];
            }
            ++prefix_cnt[prefix];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0560_H
