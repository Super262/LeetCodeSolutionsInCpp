//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0565_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0565_H

#include <vector>

using namespace std;

class Solution {
    // 根据a[i]和a[j]的关系建图，O(n)时间找到最长的环
public:
    int arrayNesting(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
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
            res = max(res, cl);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0565_H
