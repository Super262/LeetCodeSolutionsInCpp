//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0324_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0324_H

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 直接背诵！
    // 1. 找中位数：快速选择算法，O(n)
    // 2. "三数排序"：小于median的数，等于median的数，大于median的数
    // 3. 贪心：奇数位置放大于median的数，剩余位置依次摆放等于median的数、小于median的数
    void wiggleSort(vector<int> &nums) {
        const auto n = (int) nums.size();
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        auto mid = *midPtr;
        int i = 0;
        int j = 0;
        int k = n - 1;
        while (j <= k) {
            if (nums[func(j, n)] > mid) {
                swap(nums[func(i, n)], nums[func(j, n)]);
                ++i;
                ++j;
            } else if (nums[func(j, n)] < mid) {
                swap(nums[func(j, n)], nums[func(k, n)]);
                --k;
            } else {
                ++j;
            }
        }
    }

private:
    int func(const int &i, const int &n) {
        return (1 + 2 * i) % (n | 1);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0324_H
