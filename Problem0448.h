//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0448_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0448_H

#include <vector>

using namespace std;

class Solution {
    // 类似LeetCode 442的做法：设p是nums中任意数字的绝对值，设置num[p-1]=-nums[p-1]；若数字x未出现，nums[x-1]是正数
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        for (const auto &x: nums) {
            auto p = abs(x);
            if (nums[p - 1] < 0) {
                continue;
            }
            nums[p - 1] = -nums[p - 1];
        }
        for (int x = 1; x <= (int) nums.size(); ++x) {
            if (nums[x - 1] > 0) {
                ans.emplace_back(x);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0448_H
