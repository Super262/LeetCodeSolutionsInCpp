//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0066_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0066_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (auto &d: digits) {
            t += d;
            d = t % 10;
            t /= 10;
        }
        if (t) {
            digits.emplace_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0066_H
