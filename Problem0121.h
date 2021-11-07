//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0121_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0121_H

#include <vector>

using namespace std;

class Problem0121 {
public:
    int maxProfit(const vector<int> &prices) {
        int result = 0;
        int preMin = 0x3f3f3f3f;
        for (auto p: prices) {
            result = max(result, p - preMin);
            preMin = min(preMin, p);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0121_H
