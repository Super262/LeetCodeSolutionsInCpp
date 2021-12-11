//
// Created by Fengwei Zhang on 12/10/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0442_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0442_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 直接背诵代码
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (const auto &x: nums) {
            auto p = abs(x) - 1;
            nums[p] = -nums[p];
            if (nums[p] > 0) {
                result.emplace_back(p + 1);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0442_H
