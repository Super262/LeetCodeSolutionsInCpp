//
// Created by Fengwei Zhang on 11/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0128_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0128_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 巧妙的做法，要牢记！
public:
    int longestConsecutive(const vector<int> &nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int result = 0;
        for (const auto &x: nums) {  // 搜索以x为起点的最长序列
            if (!nums_set.count(x) || nums_set.count(x - 1)) {  // 存在前驱结点，跳过
                continue;
            }
            nums_set.erase(x);
            auto y = x;
            while (nums_set.count(y + 1)) {  // 探索最大后继
                nums_set.erase(y);
                ++y;
            }
            result = max(result, y - x + 1);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0128_H
