//
// Created by Fengwei Zhang on 2/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0698_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0698_H

#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    // 经典题目，必须背诵：DFS + 4个剪枝
public:
    bool canPartitionKSubsets(vector<int> &nums, const int k) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) {
            return false;
        }
        auto target = sum / k;
        bool used[nums.size()];
        memset(used, 0, sizeof used);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, nums, used, 0, target, k);
    }

private:
    bool dfs(const int st, const vector<int> &nums, bool used[], const int cur, const int target, const int k) {
        if (!k) {
            return true;
        }
        if (cur == target) {
            return dfs(0, nums, used, 0, target, k - 1);
        }
        for (auto i = st; i < (int) nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (cur + nums[i] <= target) {
                used[i] = true;
                if (dfs(i + 1, nums, used, cur + nums[i], target, k)) {
                    return true;
                }
                used[i] = false;
            }
            while (i + 1 < (int) nums.size() && nums[i + 1] == nums[i]) {
                ++i;
            }
            if (!cur || cur + nums[i] == target) {
                return false;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0698_H
