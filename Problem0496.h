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
public:
    vector<int> nextGreaterElement(const vector<int> &nums1, const vector<int> &nums2) {
        stack<int> stk;
        int answer[nums2.size()];
        for (int i = (int) nums2.size() - 1; i >= 0; --i) {
            auto x = nums2[i];
            while (!stk.empty() && stk.top() <= x) {
                stk.pop();
            }
            if (stk.empty()) {
                answer[i] = -1;
            } else {
                answer[i] = stk.top();
            }
            stk.emplace(x);
        }
        unordered_map<int, int> val_idx;
        for (int i = 0; i < nums2.size(); ++i) {
            val_idx[nums2[i]] = i;
        }
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = answer[val_idx[nums1[i]]];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0496_H
