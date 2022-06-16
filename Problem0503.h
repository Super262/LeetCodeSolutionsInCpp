//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0503_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0503_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 破环成链（将nums拷贝后，插到原nums尾部） + 单调栈（保证头部大于当前元素x，x对应的答案就是栈头；若栈为空，x对应的答案是-1）
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        const auto n = (int) nums.size();
        vector<int> ans(n);
        stack<int> stk;
        nums.insert(nums.end(), nums.begin(), nums.end());
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            auto x = nums[i];
            while (!stk.empty() && stk.top() <= x) {
                stk.pop();
            }
            if (i < n) {
                if (stk.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = stk.top();
                }
            }
            stk.emplace(x);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0503_H
