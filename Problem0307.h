//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0307_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0307_H

#include <vector>

using namespace std;

class NumArray {
    // 树状数组，要背诵O(n)时间初始化的代码
public:
    NumArray(const vector<int> &nums) {
        n = (int) nums.size();
        ft.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) { // O(n)时间初始化树状数组
            ft[i] = nums[i - 1];
            auto p = i - lowBit(i);
            for (int j = i - 1; j > p; j -= lowBit(j)) {
                ft[i] += ft[j];
            }
        }
    }

    void update(const int idx, const int val) {
        auto dist = val - (prefixSum(idx + 1) - prefixSum(idx));
        updateItem(idx + 1, dist);
    }

    int sumRange(const int left, const int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }

private:
    vector<int> ft;
    int n;

    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int val) {
        for (auto i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    int prefixSum(const int idx) {
        int result = 0;
        for (auto i = idx; i > 0; i -= lowBit(i)) {
            result += ft[i];
        }
        return result;
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
