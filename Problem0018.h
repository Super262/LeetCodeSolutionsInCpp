//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0018_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0018_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0018 {
    // 经典题目，直接背诵
public:
    vector<vector<int>> fourSum(vector<int> &nums, const int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp(4, 0);  // 公用临时结果
        for (int a = 0; a < (int) nums.size() - 3; ++a) {
            if (a && nums[a - 1] == nums[a]) {
                continue;
            }
            for (auto b = a + 1; b < (int) nums.size() - 2; ++b) {
                if (b > a + 1 && nums[b - 1] == nums[b]) {
                    continue;
                }
                temp[0] = nums[a];
                temp[1] = nums[b];
                twoSum(nums, b + 1, target - nums[a] - nums[b], temp, result);
            }
        }
        return result;
    }

private:
    void twoSum(const vector<int> &nums,
                const int start,
                const int target,
                vector<int> &temp,
                vector<vector<int>> &result) {
        if (start >= (int) nums.size() - 1) {
            return;
        }
        for (auto c = start, d = (int) nums.size() - 1; c < d; ++c) {
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
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0018_H
