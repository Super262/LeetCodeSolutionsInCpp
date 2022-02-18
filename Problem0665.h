//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0665_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0665_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：2种选择，2次检查
public:
    bool checkPossibility(vector<int> &nums) {
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            auto a = nums[i - 1];
            auto b = nums[i];
            nums[i - 1] = a;
            nums[i] = a;
            if (isNonDec(nums)) {
                return true;
            }
            nums[i - 1] = b;
            nums[i] = b;
            if (isNonDec(nums)) {
                return true;
            }
            return false;
        }
        return true;
    }

private:
    bool isNonDec(const vector<int> &nums) {
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0665_H
