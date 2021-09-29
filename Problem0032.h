//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0032_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0032_H

#include <string>
#include <vector>

using namespace std;

class Problem0032 {
    // 合法的括号序列：左括号和右括号数量相等；任意前缀中的左括号数量大于或等于右括号数量
    // 假设i是第一个不满足以上性质的位置，则合法的括号序列一定在i左侧
private:
    int longestValidParentheses(const string &s) {
        stack<int> leftIdx;
        int result = 0;
        for (int i = 0, startIdx = -1; i < (int) s.size(); ++i) {  // startIdx + 1指示合法序列的起点
            if (s[i] == '(') {
                leftIdx.emplace(i);
            } else {
                if (leftIdx.empty()) {
                    startIdx = i;
                } else {
                    leftIdx.pop();
                    if (leftIdx.empty()) {
                        result = max(result, i - startIdx);
                    } else {
                        result = max(result, i - leftIdx.top());
                    }
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0032_H
