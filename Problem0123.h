//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0123_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0123_H

#include <vector>

using namespace std;

class Problem0123 {
public:
    int maxProfit(const vector<int> &prices) {
        int f[prices.size()];
        int preMin = prices[0];
        // 1. 预处理f[i]：在第0～i天进行一次交易的最大获利
        f[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f[i] = max(f[i - 1], prices[i] - preMin);
            preMin = min(preMin, prices[i]);
        }

        int result = 0;
        int maxNext = prices[prices.size() - 1];
        // 2. 反向扫描，寻找在第i天买入（一次交易）的最大获利
        result = max(result, f[prices.size() - 1]); // 边界情况: 不进行第2次交易
        for (int i = prices.size() - 1; i >= 1; --i) {
            result = max(result, f[i - 1] + maxNext - prices[i]);
            maxNext = max(maxNext, prices[i]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0123_H
