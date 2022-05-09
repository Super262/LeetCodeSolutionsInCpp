//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0008_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0008_H

#include <string>

using namespace std;

class Solution {
    // 判断溢出：类似第7题，注意细节！不要使用 long long 类型数据
public:
    int myAtoi(const string &s) {
        int i = 0;

        // 跳过空格
        while (i < (int) s.size() && s[i] == ' ') {
            ++i;
        }
        if (i == (int) s.size()) {
            return 0;
        }

        // 搜索符号位
        bool is_neg = false;
        if (s[i] == '-') {
            ++i;
            is_neg = true;
        } else if (s[i] == '+') {
            ++i;
        }

        const auto max_tail = INT_MAX % 10;  // 记录极值的个位数字（无符号）
        const auto min_tail = INT_MIN % 10;
        const auto max_prefix = INT_MAX / 10;  // 记录极值的前缀（无符号，除去个位数字）
        const auto min_prefix = INT_MIN / 10;
        int ans = 0;
        while (i < (int) s.size() && isdigit(s[i])) {
            if (is_neg && ans < min_prefix) {
                return INT_MIN;
            }
            if (!is_neg && ans > max_prefix) {
                return INT_MAX;
            }
            auto x = s[i] - '0';
            if (is_neg) {  // 不要忘记这步：我们要保证ans的符号（正或负）和输入一致
                x = -x;
            }
            if (is_neg && ans == min_prefix && x < min_tail) {
                return INT_MIN;
            }
            if (!is_neg && ans == max_prefix && x > max_tail) {
                return INT_MAX;
            }
            ans = ans * 10 + x;
            ++i;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0008_H
