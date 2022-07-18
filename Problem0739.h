//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0739_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0739_H

#include <vector>
#include <stack>

using namespace std;

class Problem0739 {
    // 单调栈：从后向前遍历temps，将所有较小的温度值的索引i从栈顶弹出，再根据栈顶得出答案
public:
    vector<int> dailyTemperatures(const vector<int> &temps) {
        vector<int> ans(temps.size());
        stack<int> stk;
        for (auto i = (int) temps.size() - 1; i >= 0; --i) {
            while (!stk.empty() && temps[i] >= temps[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = stk.top() - i;
            }
            stk.emplace(i);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0739_H
