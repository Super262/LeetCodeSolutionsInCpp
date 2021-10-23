//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0018_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0018_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0018 {
public:
    void twoSum(const vector<int> &nums,
                const int &start,
                const int &target,
                vector<int> &temp,
                vector<vector<int>> &result) {
        if (start >= (int) nums.size() - 1) {
            return;
        }
        for (int c = start, d = (int) nums.size() - 1; c < d; ++c) {
            if (c > start && nums[c - 1] == nums[c]) {
                continue;
            }
            while (c < d && nums[c] + nums[d] > target) {
                --d;
            }
            if (c >= d) {
                return;
            }
            if (nums[c] + nums[d] == target) {
                temp[2] = nums[c];
                temp[3] = nums[d];
                result.emplace_back(temp);
            }
        }
    }

    vector<vector<int>> fourSum(vector<int> &nums, const int &target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int a = 0; a < (int) nums.size() - 3; ++a) {
            if (a > 0 && nums[a - 1] == nums[a]) {
                continue;
            }
            for (int b = a + 1; b < (int) nums.size() - 2; ++b) {
                if (b > a + 1 && nums[b - 1] == nums[b]) {
                    continue;
                }
                vector<int> temp = {nums[a], nums[b], 0, 0};
                twoSum(nums, b + 1, target - nums[a] - nums[b], temp, result);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0018_H
