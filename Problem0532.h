//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0532_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0532_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        const auto n = (int) nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            // 出现一段相同的数：跳过前面，指向最后（不能指向第一个、跳过后面，这无法处理k=0）
            while (i + 1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
            while (j < i && nums[i] - nums[j] > k) {
                ++j;
            }
            if (j < i && nums[i] - nums[j] == k) {
                ++res;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0532_H
