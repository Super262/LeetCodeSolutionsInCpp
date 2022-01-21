//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0456_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0456_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 直接掌握思路：利用单调栈记录之前元素的状态
public:
    bool find132pattern(const vector<int> &nums) {
        stack<int> stk;
        int pre_max = INT_MIN;
        for (auto i = (int) nums.size() - 1; i >= 0; --i) {  // 从后向前遍历
            auto val = nums[i];
            if (val < pre_max) {
                return true;
            }
            while (!stk.empty() && val > stk.top()) {
                pre_max = max(pre_max, stk.top());
                stk.pop();
            }
            stk.emplace(val);
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0456_H
