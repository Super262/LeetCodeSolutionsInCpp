//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0045_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0045_H

#include <vector>

using namespace std;

class Solution {
public:
    int jump(const vector<int> &nums) {
        int f[nums.size()];
        f[0] = 0;
        for (int r = 1, l = 0; r < (int) nums.size(); ++r) {
            while (l < r && l + nums[l] < r) {
                ++l;
            }
            f[r] = f[l] + 1;
        }
        return f[nums.size() - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0045_H
