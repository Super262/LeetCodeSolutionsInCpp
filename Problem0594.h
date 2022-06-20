//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0594_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0594_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 哈希表统计每个元素的频率；元素x所在的HS的长度为counter[x]+counter[x-1]
    // https://leetcode-cn.com/problems/longest-harmonious-subsequence/solution/zui-chang-he-xie-zi-xu-lie-by-leetcode-s-8cyr/
public:
    int findLHS(const vector<int> &nums) {
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            ++counter[x];
        }
        int ans = 0;
        for (const auto &item: counter) {
            auto x = item.first;
            if (!counter.count(x - 1)) {
                continue;
            }
            ans = max(ans, counter[x] + counter[x - 1]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0594_H
