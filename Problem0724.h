//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0724_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0724_H

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Problem0724 {
    // 遍历，累计前缀和s，判断2*s=sum-nums[i]是否成立
public:
    int pivotIndex(const vector<int> &nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, s = 0; i < nums.size(); ++i) {
            if (2 * s == sum - nums[i]) {
                return i;
            }
            s += nums[i];
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0724_H
