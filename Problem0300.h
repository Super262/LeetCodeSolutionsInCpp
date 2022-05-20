//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0300_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0300_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // 贪心算法，二分查找实现，参考AcWing 896
public:
    int lengthOfLIS(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int lis_tail[n + 1];
        memset(lis_tail, 0x3f, sizeof lis_tail);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            const auto &t = nums[i];
            int l = 0;
            int r = ans;
            while (l < r) {
                auto mid = l + (r - l + 1) / 2;
                if (lis_tail[mid] >= t) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            lis_tail[l + 1] = min(lis_tail[l + 1], t);
            ans = max(ans, l + 1);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0300_H
