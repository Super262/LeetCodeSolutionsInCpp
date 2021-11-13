//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0189_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0189_H

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= (int) nums.size();
        if (k == 0) {
            return;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0189_H
