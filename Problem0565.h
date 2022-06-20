//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0565_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0565_H

#include <vector>

using namespace std;

class Solution {
    // 暴力枚举，枚举所有可行的起点num[i]，向后探索直到发现重复；这里我们做了非常多重复操作
    // 如果路径p不是最长的，那么所有包含路径p的路径s也都不是最长的；因此，我们标记上次探索被发现的点为-1，避免重复搜索，优化时间为O(n)
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] == -1) {
                continue;
            }
            auto j = i;
            int cl = 0;
            while (nums[j] != -1) {
                ++cl;
                auto next = nums[j];
                nums[j] = -1;
                j = next;
            }
            ans = max(ans, cl);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0565_H
