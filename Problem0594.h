//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0594_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0594_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // https://leetcode-cn.com/problems/longest-harmonious-subsequence/solution/zui-chang-he-xie-zi-xu-lie-by-leetcode-s-8cyr/
public:
    int findLHS(const vector<int> &nums) {
        unordered_map<int, int> counter;
        for (const auto &x: nums) {
            ++counter[x];
        }
        int res = 0;
        for (const auto &item: counter) {
            auto x = item.first;
            if (!counter.count(x - 1)) {
                continue;
            }
            res = max(res, counter[x] + counter[x - 1]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0594_H
