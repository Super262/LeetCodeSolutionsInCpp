//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0128_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0128_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 巧妙的做法，要牢记：利用哈希表保存前缀，快速查找a的前驱a-1是否存在
public:
    int longestConsecutive(const vector<int> &nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int res = 0;
        for (const auto &l: nums) {  // 搜索以l为起点的最长序列
            if (!nums_set.count(l) || nums_set.count(l - 1)) {  // 存在前驱结点，跳过
                continue;
            }
            auto r = l;
            while (nums_set.count(r)) {  // 探索最大后继r-1
                nums_set.erase(r);
                ++r;
            }
            res = max(res, r - l);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0128_H
