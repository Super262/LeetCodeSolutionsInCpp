//
// Created by Fengwei Zhang on 4/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1019_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1019_H

#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // 单调栈问题：栈内除了保存数值，还有下标
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        stack<pair<int, int>> stk;  // 保存(值,ans下标)
        int i = 0;
        while (head) {
            while (!stk.empty() && head->val > stk.top().first) {
                auto t = stk.top();
                ans[t.second] = head->val;
                stk.pop();
            }
            ans.emplace_back(0);
            stk.emplace(head->val, i);
            ++i;
            head = head->next;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1019_H
