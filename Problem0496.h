//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0496_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0496_H

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    // 对nums2中每个元素nums2[i]，记录下个更大元素next_greater[i]（利用单调栈）
    // 记录nums2中每个元素的索引val_idx，那么最终结果中第i个元素是next_greater[val_idx[nums1[i]]]
public:
    vector<int> nextGreaterElement(const vector<int> &nums1, const vector<int> &nums2) {
        stack<int> stk;
        int next_greater[nums2.size()];
        for (int i = (int) nums2.size() - 1; i >= 0; --i) {
            auto x = nums2[i];
            while (!stk.empty() && stk.top() <= x) {
                stk.pop();
            }
            if (stk.empty()) {
                next_greater[i] = -1;
            } else {
                next_greater[i] = stk.top();
            }
            stk.emplace(x);
        }
        unordered_map<int, int> val_idx;
        for (int i = 0; i < (int) nums2.size(); ++i) {
            val_idx[nums2[i]] = i;
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < (int) nums1.size(); ++i) {
            ans[i] = next_greater[val_idx[nums1[i]]];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0496_H
