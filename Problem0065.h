//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0065_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0065_H

#include <string>

using namespace std;

class Problem0065 {
    // 经典算法，直接背诵
    // 1. 去掉字符串开始和末尾的空格
    // 2. e前面或后面如果是空的，则不合法
    // 3. e的后面不能有小数
    // 4. 不能有连续多个正负符号
    // 5. e和'.'最多出现1次
public:
    bool isNumber(const string &s) {
        int st = 0;
        auto ed = (int) s.size() - 1;  // s[st:ed]表示有效的字符串部分

        // 首部、尾部去空格
        while (st <= ed && s[st] == ' ') {
            ++st;
        }
        while (st <= ed && s[ed] == ' ') {
            --ed;
        }
        if (st > ed) {
            return false;
        }

        // 判断正负号是否合法并去掉符号位
        if (s[st] == '+' || s[st] == '-') {
            ++st;
        }
        if (st > ed) {
            return false;
        }

        // 浮点数是否合法：".4"是合法的
        if (s[st] == '.' && (ed - st + 1 == 1 || s[st + 1] == 'e' || s[st + 1] == 'E')) {
            return false;
        }

        bool has_dot = false;
        bool has_exp = false;
        for (int i = st; i <= ed; ++i) {
            if (s[i] == '.') {
                if (has_dot || has_exp) {  // 小数点多次出现或小数在e后出现，不合法
                    return false;
                }
                has_dot = true;
                continue;
            }
            if (s[i] == 'e' || s[i] == 'E') {
                if (has_exp || i == st || i == ed) {  // e在首位出现或e后无数字，不合法
                    return false;
                }
                has_exp = true;
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == ed + 1) {  // e后有符号位但符号位后无数字，不合法
                        return false;
                    }
                    ++i;
                }
                continue;
            }
            if (!isdigit(s[i])) {  // 非数字出现，不合法
                return false;
            }
        }

        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0065_H
