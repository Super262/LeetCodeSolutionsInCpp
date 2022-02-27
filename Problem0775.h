//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0775_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0775_H

#include <cmath>
#include <vector>

using namespace std;

class Solution {
    // 由于A是[0, n - 1]的排列，当(i - A[i]) <= 1，全局倒置与局部倒置相等
    // https://www.acwing.com/solution/content/24554/
public:
    bool isIdealPermutation(const vector<int> &nums) {
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (abs(i - nums[i]) > 1) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0775_H
