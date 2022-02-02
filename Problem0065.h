//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0065_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0065_H

#include <string>

using namespace std;

// 1. 去掉字符串开始和末尾的空格
// 2. e前面或后面如果是空的，则不合法
// 3. e的后面不能有小数
// 4. 不能有连续多个正负符号
// 5. e和'.'最多出现1次
class Solution {
public:
    bool isNumber(string s) {
        // 首部、尾部去空格
        int l = 0, r = (int) s.size() - 1;
        while (l <= r && s[l] == ' ') {
            ++l;
        }
        while (l <= r && s[r] == ' ') {
            --r;
        }
        if (l > r) {
            return false;
        }
        s = s.substr(l, r - l + 1);

        // 判断正负号是否合法并去掉符号位
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        if (s.empty()) {
            return false;
        }

        // 浮点数是否合法：".4"是合法的
        if (s[0] == '.' && (s.size() == 1 || s[1] == 'e' || s[1] == 'E')) {
            return false;
        }

        bool has_dot = false;
        bool has_exp = false;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] == '.') {
                if (has_dot || has_exp) {  // 小数点多次出现或小数在e后出现，不合法
                    return false;
                }
                has_dot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (has_exp || i == 0 || i + 1 == s.size()) {  // e多次出现或e后无数字，不合法
                    return false;
                }
                has_exp = true;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) {  // e后有符号位但符号位后无数字，不合法
                        return false;
                    }
                    ++i;
                }
            } else if (!isdigit(s[i])) {  // 非数字出现，不合法
                return false;
            }
        }

        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0065_H
