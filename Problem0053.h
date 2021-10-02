//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0053_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0053_H

#include <vector>

using namespace std;

class Problem0053 {
public:
    int maxSubArray(const vector<int> &nums) {
        auto currentMax = nums[0];
        auto result = currentMax;
        for (int i = 1; i < (int) nums.size(); ++i) {
            currentMax = max(nums[i], currentMax + nums[i]);
            result = max(result, currentMax);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0053_H
