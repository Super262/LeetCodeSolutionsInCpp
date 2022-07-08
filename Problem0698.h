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
    // 经典题目，DFS + 4个剪枝；我们枚举每个数字nums[i]的使用情况，尝试构建k个相同数字
    // 剪枝1：DFS前，降序排序nums，先尝试较大元素
    // 剪枝2：若nums[i]不可行，跳过i后面和nums[i]相等的其它元素
    // 剪枝3、4：若尝试nums[i]失败，当前正处理头部或尾部，说明本层DFS必失败，直接返回false
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
