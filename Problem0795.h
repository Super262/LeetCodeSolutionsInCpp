//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0795_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0795_H

#include <vector>

using namespace std;

class Problem0795 {
    // 暴力统计，类似前缀和；countSubArrays(n)返回最大元素不超过n的数组的个数，答案即为countSubArrays(r)-countSubArrays(l-1)
    // countSubArrays(n)：若发现区段[l,r)满足最大值不超过n，设k=r-l，那么最大值不超过n的子数组有(k+1)*k/2个
public:
    int numSubarrayBoundedMax(const vector<int> &nums, int left, int right) {
        return (int) (countSubArrays(nums, right) - countSubArrays(nums, left - 1));
    }

private:
    unsigned long long countSubArrays(const vector<int> &nums, int limit) {
        unsigned long long ans = 0;
        for (int l = 0; l < (int) nums.size(); ++l) {
            if (nums[l] > limit) {
                continue;
            }
            auto r = l + 1;
            while (r < (int) nums.size() && nums[r] <= limit) {
                ++r;
            }
            auto k = r - l;
            ans += (unsigned long long) (k + 1) * k / 2;  // 长度为k的数组有 (k + 1) * k / 2 个非空子数组
            l = r - 1;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0795_H
