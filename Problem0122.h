//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0122_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0122_H

#include <vector>

using namespace std;

class Solution {
    // 一段时间内的交易 == 多个单天的交易
public:
    int maxProfit(const vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < (int) prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0122_H
