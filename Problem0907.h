//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0907_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0907_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 采用类似891题的解法，单调栈预处理区间边界，计算每个数字对最终答案的贡献
    // 注意处理重复值：若两个元素相同，我们认为所在索引小的元素更小
public:
    int sumSubarrayMins(const vector<int> &arr) {
        const auto n = (int) arr.size();
        int left[n];
        int right[n];
        stack<int> stk;
        for (int i = 0; i < (int) arr.size(); ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                left[i] = -1;
            } else {
                left[i] = stk.top();
            }
            stk.emplace(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                right[i] = n;
            } else {
                right[i] = stk.top();
            }
            stk.emplace(i);
        }
        int ans = 0;
        const int M = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (int) ((ans + (long long) (i - left[i]) * (right[i] - i) * arr[i]) % M);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0907_H
