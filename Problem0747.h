
//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0747_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0747_H

#include <vector>

using namespace std;

class Problem0747 {
    // 先找到最大值，再逐一验证
public:
    int dominantIndex(const vector<int> &nums) {
        int k = 0;
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] > nums[k]) {
                k = i;
            }
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (i != k && 2ll * nums[i] > nums[k]) {
                return -1;
            }
        }
        return k;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0747_H
