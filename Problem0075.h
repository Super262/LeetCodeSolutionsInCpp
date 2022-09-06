//
// Created by Fengwei Zhang on 10/28/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0075_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0075_H

#include <vector>

using namespace std;

class Problem0075 {
    // 经典算法，直接背诵：交换目标元素到特定位置
public:
    void sortColors(vector<int> &nums) {
        int i = 0;
        int j = 0;
        auto k = (int) nums.size() - 1;
        while (j <= k) {  // 继续条件是j<=k，不是j<k
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            } else if (nums[j] == 1) {
                ++j;
            } else {
                swap(nums[j], nums[k]);
                --k;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0075_H
