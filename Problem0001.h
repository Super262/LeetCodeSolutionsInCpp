//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0001_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0001_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < (int) nums.size(); ++i) {
            auto y = target - nums[i];
            if (num_to_idx.count(y)) {
                return {num_to_idx[y], i};
            }
            num_to_idx[nums[i]] = i;
        }
        return {};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0001_H
