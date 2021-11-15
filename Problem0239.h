//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0239_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0239_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int> &nums, const int &k) {
        int q[nums.size() + 1];
        int hh = 0, tt = -1;
        vector<int> result(nums.size() - (k - 1), 0);
        int resTop = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (hh <= tt && q[tt] - q[hh] + 1 == k) {
                ++hh;
            }
            while (hh <= tt && nums[q[tt]] <= nums[i]) {
                --tt;
            }
            q[++tt] = i;
            if (i >= k - 1) {
                result[resTop++] = nums[q[hh]];
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0239_H
