//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0456_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0456_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 贪心算法：从后向前遍历数组nums，变量pre_max存储当前nums[k]的最大值，栈stk存储nums[k]的候选值，栈顶是当前nums[j]的最小值
    // 遍历到当前元素nums[i]时，弹出stk中较小元素，并更新pre_max（当前nums[k]的最大值），再将当前元素入栈
    // 因此，pre_max < stk.top() 始终成立，若当前数字 x < pre_max 也成立，说明"132模式"存在
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
