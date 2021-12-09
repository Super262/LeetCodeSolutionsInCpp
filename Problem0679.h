//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0679_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0679_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgePoint24(const vector<int> &cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }

private:
    bool dfs(const vector<double> &nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-8;
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }
                auto a = nums[i];
                auto b = nums[j];
                if (dfs(replace(nums, i, j, a + b))) {
                    return true;
                }
                if (dfs(replace(nums, i, j, a - b))) {
                    return true;
                }
                if (dfs(replace(nums, i, j, a * b))) {
                    return true;
                }
                if (b != 0 && dfs(replace(nums, i, j, a / b))) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<double> replace(const vector<double> &nums, int x, int y, double z) {
        vector<double> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == x || i == y) {
                continue;
            }
            result.emplace_back(nums[i]);
        }
        result.emplace_back(z);
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0679_H
