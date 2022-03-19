//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0398_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0398_H

#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
public:
    Solution(const vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            num2Idx[nums[i]].emplace_back(i);
        }
    }

    int pick(const int &target) {
        return num2Idx[target][random() % num2Idx[target].size()];
    }

private:
    unordered_map<int, vector<int>> num2Idx;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0398_H
