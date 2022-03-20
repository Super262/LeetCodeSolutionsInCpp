//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0303_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0303_H

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(const vector<int> &nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    int sumRange(const int &left, const int &right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0303_H
