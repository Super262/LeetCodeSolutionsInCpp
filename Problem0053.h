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
        auto cur_max = nums[0];
        auto result = cur_max;
        for (int i = 1; i < (int) nums.size(); ++i) {
            cur_max = max(nums[i], cur_max + nums[i]);
            result = max(result, cur_max);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0053_H
