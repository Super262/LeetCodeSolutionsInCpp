//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0307_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0307_H

#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> ft;
    int n;

    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int val) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    int prefixSum(const int idx) {
        int result = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            result += ft[i];
        }
        return result;
    }

public:
    NumArray(const vector<int> &nums) {
        n = (int) nums.size();
        ft = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            updateItem(i, nums[i - 1]);
        }
    }

    void update(const int idx, const int val) {
        auto dist = val - (prefixSum(idx + 1) - prefixSum(idx));
        updateItem(idx + 1, dist);
    }

    int sumRange(const int left, const int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0307_H
