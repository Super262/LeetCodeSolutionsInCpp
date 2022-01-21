//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0448_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0448_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> result;
        for (const auto &x: nums) {
            auto i = abs(x);
            if (nums[i - 1] < 0) {
                continue;
            }
            nums[i - 1] = -nums[i - 1];
        }
        for (int x = 1; x <= nums.size(); ++x) {
            if (nums[x - 1] > 0) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0448_H
