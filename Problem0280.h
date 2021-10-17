//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0280_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0280_H

#include <vector>

using namespace std;

class Problem0280 {
public:
    void wiggleSort(vector<int> &nums) {
        for (int i = 1; i < (int) nums.size(); ++i) {
            if ((i % 2 != 0 && nums[i - 1] > nums[i]) || (i % 2 == 0 && nums[i - 1] < nums[i])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0280_H
