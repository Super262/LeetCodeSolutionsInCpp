//
// Created by Fengwei Zhang on 9/30/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0042_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0042_H

#include <vector>
#include <stack>

using namespace std;

class Problem0042 {
public:
    int trap(const vector<int> &height) {
        stack<int> stk;  // 单调栈，体积递减
        int result = 0;
        for (int i = 0; i < (int) height.size(); ++i) {
            int prev_h = 0;
            while (!stk.empty() && height[i] >= height[stk.top()]) {  // 高度分布：次高(top)，低(prev_h)，最高（i）
                result += (i - stk.top() - 1) * (height[stk.top()] - prev_h);
                prev_h = height[stk.top()];
                stk.pop();
            }
            if (!stk.empty()) {  // 高度分布：最高(top)，低(prev_h)，次高（i）
                result += (i - stk.top() - 1) * (height[i] - prev_h);
            }
            stk.emplace(i);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0042_H
