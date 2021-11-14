//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0238_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0238_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 1; i < (int) nums.size(); ++i) {
            prefix *= nums[i - 1];
            result[i] *= prefix;
        }
        int suffix = 1;
        for (int i = (int) nums.size() - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            result[i] *= suffix;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0238_H
