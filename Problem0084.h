//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0084_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0084_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    int largestRectangleArea(const vector<int> &heights) {
        const auto n = (int) heights.size();
        vector<int> stk;
        stk.reserve(n);

        // 求左边界，边界值为-1
        int left_bro[n];
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                left_bro[i] = -1;
            } else {
                left_bro[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        // 清空栈！！
        stk.clear();

        // 求右边界，边界值为n
        int right_bro[n];
        for (auto i = n - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                right_bro[i] = n;
            } else {
                right_bro[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, (right_bro[i] - left_bro[i] - 1) * heights[i]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0084_H
