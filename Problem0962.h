//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0962_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0962_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 预处理：前缀最小值和后缀最大值
    // 滑动窗口[l:r]：若pre_min[l] <= suf_max[r]，说明ans >= r - l，因为比pre_min[l]更大的数的索引大于或等于r，r后移；
    // 若pre_min[l] > suf_max[r]，说明[0:l]间不存在比max[r,n-1]更小的数，l后移
public:
    int maxWidthRamp(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int pre_min[n];
        int suf_max[n];
        pre_min[0] = nums[0];
        suf_max[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            pre_min[i] = min(pre_min[i - 1], nums[i]);
        }
        for (auto i = n - 2; i >= 0; --i) {
            suf_max[i] = max(suf_max[i + 1], nums[i]);
        }
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            if (pre_min[l] <= suf_max[r]) {
                ans = max(ans, r - l);
                continue;
            }
            ++l;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0962_H
