//
// Created by Fengwei Zhang on 5/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0294_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0294_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // SG函数模版题，必须掌握
    // 题解1：https://www.1point3acres.com/bbs/thread-137953-1-1.html
    // SG讲解：https://zhuanlan.zhihu.com/p/20611132
    // 其它题解：https://leetcode.cn/problems/flip-game-ii/solution/c-sprague-grundy-acmbo-yi-lun-xiang-guan-1ddj/
public:
    bool canWin(const string &s) {
        const auto n = (int) s.size();
        int memo[n + 1];
        memset(memo, -1, sizeof memo);
        memo[0] = 0;
        memo[1] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {  // 将s分解为多个子状态s[i:j-1]，包含(j-i)个"+"
            auto j = i;
            while (j < n && s[j] == '+') {
                ++j;
            }
            ans ^= sg(j - i, memo);
            i = j;
        }
        return ans > 0;
    }

private:
    int sg(int x, int memo[]) {
        if (memo[x] != -1) {
            return memo[x];
        }
        bool existed[x + 1];  // existed[x]：非负整数x是否出现
        memset(existed, 0, sizeof existed);
        for (int i = 0; i + 2 <= x; ++i) {  // 翻转[i:i+1]，剩余的子状态为s[0:i-1]和s[i+2,x-1]，分别含有0个和(x-i-2)个"+"
            existed[sg(i, memo) ^ sg(x - (i + 2), memo)] = true;
        }
        for (int i = 0; i <= x; ++i) {
            if (!existed[i]) {
                memo[x] = i;
                return i;
            }
        }
        return 0;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0294_H
