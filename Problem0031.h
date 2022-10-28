//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0031_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0031_H

#include <vector>

using namespace std;

class Problem0031 {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 3) {  // 特殊情况：序列长度小于3，直接反序
            reverse(nums.begin(), nums.end());
            return;
        }
        auto k = (int) nums.size() - 2;
        while (k >= 0 && nums[k] >= nums[k + 1]) {  // 找到不递增序列前的元素（注意：这里使用">="）
            --k;
        }
        if (k < 0) {  // 整个序列为不递增序列
            reverse(nums.begin(), nums.end());
            return;
        }
        auto min_gre_idx = k + 1;
        while (min_gre_idx + 1 < nums.size() && nums[min_gre_idx + 1] > nums[k]) {  // 不递增序列中搜索比nums[k]大的最小数
            ++min_gre_idx;
        }
        swap(nums[min_gre_idx], nums[k]);  // 交换
        reverse(nums.begin() + k + 1, nums.end()); // 反序原不递增序列
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0031_H
