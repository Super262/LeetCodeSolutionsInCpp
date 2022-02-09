//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0643_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0643_H

#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(const vector<int> &nums, int k) {
        int res = INT_MIN;
        for (int l = 0, r = 0, temp = 0; r < (int) nums.size(); ++r) {
            temp += nums[r];
            if (r - l + 1 > k) {
                temp -= nums[l];
                ++l;
            }
            if (r - l + 1 == k) {
                res = max(res, temp);
            }
        }
        return (double) res / k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0643_H
