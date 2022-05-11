//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0066_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0066_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 类似大整数加法：从低位到高位依次进位
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (auto &d: digits) {
            t += d;
            d = t % 10;
            t /= 10;
            if (!t) {  // 没有新的进位，终止
                break;
            }
        }
        if (t) {
            digits.emplace_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0066_H
