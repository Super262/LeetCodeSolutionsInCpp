//
// Created by Fengwei Zhang on 9/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0001_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0001_H

#include <unordered_map>
#include <vector>

using namespace std;

class Problem0001 {
private:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> numIdx;
        for (int i = 0; i < (int) nums.size(); ++i) {
            auto y = target - nums[i];
            if (numIdx.count(y)) {
                result.emplace_back(numIdx[y]);
                result.emplace_back(i);
                break;
            }
            numIdx[nums[i]] = i;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0001_H
