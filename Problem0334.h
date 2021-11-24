//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0334_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0334_H

#include <vector>

using namespace std;

class Solution {
    // 判断LIS的长度是否至少为3
public:
    bool increasingTriplet(const vector<int> &nums) {
        if (nums.size() < 3) {
            return false;
        }
        int result = 0;
        vector<int> lisTail(4, INT_MAX);
        lisTail[0] = INT_MIN;
        for (int num : nums) {
            int k = 0;
            while (k <= result && lisTail[k] < num) {
                ++k;
            }
            result = max(result, k);
            lisTail[k] = min(num, lisTail[k]);
            if (result >= 3) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0334_H
