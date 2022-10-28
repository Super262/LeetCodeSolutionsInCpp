//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0007_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0007_H

#include <algorithm>

using namespace std;

class Problem0007 {
    // 评测系统不允许使用long long类型
    // 溢出判断：若当前待加入的个位数字是x，若不溢出，INT_MIN <= ans * 10 + x <= INT_MAX成立
    // 设INT_MAX的个位数字是max_tail，则 (ans < INT_MAX / 10) || (ans == INT_MAX / 10 && x <= max_tail) 成立；同理INT_MIN
public:
    int reverse(int x) {
        int ans = 0;
        const auto max_tail = INT_MAX % 10;  // 记录极值的个位数字
        const auto min_tail = INT_MIN % 10;
        const auto max_prefix = INT_MAX / 10;  // 记录极值的前缀（除去个位数字）
        const auto min_prefix = INT_MIN / 10;
        while (x) {
            if (ans > max_prefix || ans < min_prefix) {  // 溢出
                return 0;
            }
            auto y = x % 10;
            if (ans == max_prefix && y > max_tail) {  // 加入个位数字后，上溢
                return 0;
            }
            if (ans == min_prefix && y < min_tail) {  // 加入个位数字后，下溢
                return 0;
            }
            ans = ans * 10 + y;
            x /= 10;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0007_H
