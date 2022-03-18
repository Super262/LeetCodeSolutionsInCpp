//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0503_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0503_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 破环成链 + 单调栈
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        const auto n = (int) nums.size();
        vector<int> res(n);
        stack<int> stk;
        nums.insert(nums.end(), nums.begin(), nums.end());
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            auto x = nums[i];
            while (!stk.empty() && stk.top() <= x) {
                stk.pop();
            }
            if (i < n) {
                if (stk.empty()) {
                    res[i] = -1;
                } else {
                    res[i] = stk.top();
                }
            }
            stk.emplace(x);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0503_H
