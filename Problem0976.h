//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0976_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0976_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 排序，从大到小枚举3条边a、b、c，返回第1个可行的解
public:
    int largestPerimeter(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (auto i = (int) nums.size() - 3; i >= 0; --i) {
            auto a = nums[i + 2];
            auto b = nums[i + 1];
            auto c = nums[i];
            if (b + c > a) {  // 短边的和大于长边
                return a + b + c;
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0976_H
