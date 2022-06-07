//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0473_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0473_H

#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    // 模版题，扩展题目：AcWing 167
    // 5个剪枝：从短到长枚举火柴；每条边内部火柴编号递增；
    // 若当前放置某根火柴失败：跳过长度相同的火柴；若是第一根火柴，则剪掉当前分枝；若是最后一根，也剪掉当前分枝
public:
    bool makesquare(vector<int> &sticks) {
        auto sum = accumulate(sticks.begin(), sticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        bool used[sticks.size()];
        memset(used, 0, sizeof used);
        sort(sticks.begin(), sticks.end(), greater<int>());
        return dfs(0, 0, sum / 4, 1, sticks, used);
    }

private:
    bool dfs(int s_idx, int length, int target, int e_cnt, const vector<int> &nums, bool used[]) {
        if (e_cnt > 4) {
            return true;
        }
        if (length == target) {
            return dfs(0, 0, target, e_cnt + 1, nums, used);
        }
        for (auto i = s_idx; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            if (dfs(i + 1, length + nums[i], target, e_cnt, nums, used)) {
                return true;
            }
            used[i] = false;
            if (length == 0 || length + nums[i] == target) {  // 第一根火柴或最后一根
                return false;
            }
            while (i + 1 < (int) nums.size() && nums[i + 1] == nums[i]) {  // 跳过相同长度的火柴
                ++i;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0473_H
