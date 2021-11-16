//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0268_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0268_H

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(const vector<int> &nums) {
        const int n = (int) nums.size();
        int allSum = 0;
        for (const auto &x: nums) {
            allSum += x;
        }
        return (n + 1) * n / 2 - allSum;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0268_H
