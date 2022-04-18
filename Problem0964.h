//
// Created by Fengwei Zhang on 4/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0964_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0964_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 我们将t看作是一个x进制数，首先处理最低位，再递归处理高位
    // 假设t % x = r，处理最低位r时，有2种选择：加上r个1，t /= x；减去(x - r)个1，t = t / x + 1；
    // 因此，k（当前需要补全x^k位）影响最终结果，递归过程中需要记录k（depth）
    // 若当前要加上1，即x^0，操作为"+x/x"，共2个运算符；若当前要加上x^k，操作为"+x*...*x"，共k个运算符；减法同理
    // t为1时，递归结束；使用记忆化搜索来优化递归
    // https://www.acwing.com/solution/content/756/
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<string, int> memo;
        return dfs(target, 0, x, memo);
    }

private:
    int dfs(int cur, int depth, int x, unordered_map<string, int> &memo) {
        if (!cur) {
            return -1;  // -1 为去除开头的正号
        }
        auto cost = depth ? depth : 2;
        if (cur == 1) {
            return cost - 1;  // -1 为去除开头的正号
        }
        auto key = to_string(depth) + '#' + to_string(cur);
        if (memo.count(key)) {
            return memo[key];
        }
        auto r = cur % x;
        cur /= x;
        if (!r) {
            auto ans = dfs(cur, depth + 1, x, memo);
            memo[key] = ans;
            return ans;
        }
        auto ans = min(dfs(cur, depth + 1, x, memo) + cost * r,
                       dfs(cur + 1, depth + 1, x, memo) + cost * (x - r));
        memo[key] = ans;
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0964_H
