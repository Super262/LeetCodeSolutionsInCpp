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
        unordered_map<int, int> numCount;
        for (int i = 0; i < (int) nums.size(); ++i) {
            auto y = target - nums[i];
            if (numCount.count(y)) {
                result.emplace_back(numCount[y]);
                result.emplace_back(i);
                break;
            }
            numCount[nums[i]] = i;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0001_H
