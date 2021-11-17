//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0300_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0300_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums) {
        const int n = (int) nums.size();
        int lisTail[n + 1];
        memset(lisTail, 0x3f, sizeof lisTail);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            const auto &t = nums[i];
            int l = 0;
            int r = result;
            while (l < r) {
                auto mid = l + (r - l + 1) / 2;
                if (lisTail[mid] >= t) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            lisTail[l + 1] = min(lisTail[l + 1], t);
            result = max(result, l + 1);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0300_H
