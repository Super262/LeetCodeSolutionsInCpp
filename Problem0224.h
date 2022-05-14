//
// Created by Fengwei Zhang on 9/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0224_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0224_H

#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
    // 运算符只有"+"和"-"
public:
    int calculate(const string &s) {
        stack<int> ops;
        int sign = 1;
        auto n = (int) s.size();
        int i = 0;
        int ans = 0;
        ops.emplace(sign);  // 预先压入一个"+"
        while (i < n) {
            if (s[i] == ' ') {  // 跳过空格
                ++i;
                continue;
            }
            if (s[i] == '+') {
                sign = ops.top();
                ++i;
                continue;
            }
            if (s[i] == '-') {
                sign = -ops.top();
                ++i;
                continue;
            }
            if (s[i] == '(') {
                ops.emplace(sign);
                ++i;
                continue;
            }
            if (s[i] == ')') {
                ops.pop();
                ++i;
                continue;
            }
            long long num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                ++i;
            }
            ans += (int) (sign * num);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0224_H
