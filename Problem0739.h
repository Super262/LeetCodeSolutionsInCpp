//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0739_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0739_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int> &temperatures) {
        vector<int> res(temperatures.size());
        stack<int> stk;
        for (auto i = (int) temperatures.size() - 1; i >= 0; --i) {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                res[i] = 0;
            } else {
                res[i] = stk.top() - i;
            }
            stk.emplace(i);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0739_H
