//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0697_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0697_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 设first_idx[i]是i首次出现的位置、last_idx[i]是i最后出现的位置；若数字x是频率最高的数字，那么答案就是last_idx[x]-first_idx[x]
    // 如果有多个满足要求的数字x，我们取最小值min({last_idx[x]-first_idx[x]})
public:
    int findShortestSubArray(const vector<int> &nums) {
        unordered_map<int, int> counter;  // 数字出现的频率
        unordered_map<int, int> first_idx;  // 某个数字第一次出现的位置
        unordered_map<int, int> last_idx;  // 某个数字第二次出现的位置
        int degree = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            auto x = nums[i];
            if (!counter.count(x)) {
                first_idx[x] = i;
            }
            ++counter[x];
            last_idx[x] = i;
            degree = max(degree, counter[x]);
        }
        int ans = INT_MAX;
        for (const auto &x: nums) {
            if (counter[x] != degree) {
                continue;
            }
            ans = min(ans, last_idx[x] - first_idx[x] + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0697_H
