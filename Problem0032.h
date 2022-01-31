//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0032_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0032_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 合法的括号序列：左括号和右括号数量相等；任意前缀中的左括号数量大于或等于右括号数量
    // 假设i是第一个不满足以上性质的位置，则合法的括号序列一定在i左侧
public:
    int longestValidParentheses(const string &s) {
        stack<int> left_idx;
        int result = 0;
        for (int i = 0, st = 0; i < (int) s.size(); ++i) {  // st 指示合法序列的起点
            if (s[i] == '(') {
                left_idx.emplace(i);
                continue;
            }
            if (left_idx.empty()) {
                st = i + 1;
                continue;
            }
            left_idx.pop();
            if (left_idx.empty()) {
                result = max(result, i - st + 1);
            } else {
                result = max(result, i - left_idx.top());
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0032_H
