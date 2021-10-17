//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0136_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0136_H

#include <vector>

using namespace std;

class Problem0136 {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (const int &a: nums) {
            result ^= a;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0136_H
