//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0442_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0442_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 技巧：设p是nums中任意数字的绝对值，设置num[p-1]=-nums[p-1]；若数字x重复出现，nums[x-1]是正数（负负为正）
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ans;
        for (const auto &x: nums) {
            auto p = abs(x);
            nums[p - 1] = -nums[p - 1];
            if (nums[p - 1] > 0) {
                ans.emplace_back(p);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0442_H
