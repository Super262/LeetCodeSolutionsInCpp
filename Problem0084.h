//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0084_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0084_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Problem0084 {
private:
    int largestRectangleArea(const vector<int> &heights) {
        vector<int> stk;
        int leftH[heights.size()];
        int rightH[heights.size()];

        // 求左边界
        for (int i = 0; i < (int) heights.size(); ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                leftH[i] = -1;
            } else {
                leftH[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        // 清空栈！！
        stk.clear();

        // 求右边界
        for (int i = (int) heights.size() - 1; i >= 0; --i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            if (stk.empty()) {
                rightH[i] = (int) heights.size();
            } else {
                rightH[i] = stk.back();
            }
            stk.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < (int) heights.size(); ++i) {
            result = max(result, (rightH[i] - leftH[i] - 1) * heights[i]);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0084_H
