//
// Created by Fengwei Zhang on 5/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0255_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0255_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 巧妙思路：单调栈，当遇到比栈顶元素大的数的时候，说明从左子树到了右子树
    // 我们记录左子树的最大值为max_prev，若右子树中有值比max_prev小，说明输入非法
public:
    bool verifyPreorder(const vector<int> &preorder) {
        stack<int> stk;
        int prev_max = INT_MIN;
        for (const auto &x: preorder) {
            if (x < prev_max) {
                return false;
            }
            while (!stk.empty() && x > stk.top()) {
                prev_max = stk.top();
                stk.pop();
            }
            stk.emplace(x);
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0255_H
