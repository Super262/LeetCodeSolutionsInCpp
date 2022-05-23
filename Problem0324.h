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
    // 快速选择 + 三数排序：https://www.acwing.com/solution/content/350/
    // 我们先用快速选择算法求出中位数mid，C++中可以调用 nth_element()函数
    // 将所有数分成三种：小于mid的数、等于mid的数和大于mid的数
    // 然后对数组排序，使得大于mid的数在最前面，等于mid的数在中间，小于mid的数在最后面
    // i => (1 + 2 * i) % (n | 1)，该映射可以将数组前一半映射到奇数位置上，数组后一半映射到偶数位置上
public:
    void wiggleSort(vector<int> &nums) {
        const auto n = (int) nums.size();
        auto mid_ptr = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        auto median = *mid_ptr;
        int i = 0;
        int j = 0;
        int k = n - 1;
        while (j <= k) {
            if (nums[func(j, n)] > median) {
                swap(nums[func(i, n)], nums[func(j, n)]);
                ++i;
                ++j;
            } else if (nums[func(j, n)] < median) {
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
