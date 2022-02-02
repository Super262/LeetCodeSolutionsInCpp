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
        vector<int> stk;
        stk.reserve(heights.size());

        // 求左边界
        int left_bro[heights.size()];
        for (int i = 0; i < (int) heights.size(); ++i) {
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

        // 求右边界
        int right_bro[heights.size()];
        for (int i = (int) heights.size() - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                right_bro[i] = (int) heights.size();
            } else {
                right_bro[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < (int) heights.size(); ++i) {
            result = max(result, (right_bro[i] - left_bro[i] - 1) * heights[i]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0084_H
