//
// Created by Fengwei Zhang on 1/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0477_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0477_H

#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(const vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            int a = 0, b = 0;
            for (const auto &x: nums) {
                if ((x >> i) & 1) {
                    ++a;
                } else {
                    ++b;
                }
            }
            res += a * b;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0477_H
