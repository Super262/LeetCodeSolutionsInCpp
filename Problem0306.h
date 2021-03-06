//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0306_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0306_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 不断尝试枚举所有数字可能的起点和终点位置，直到发现可行解
public:
    bool isAdditiveNumber(const string &num) {
        for (int i = 0; i < (int) num.size(); ++i) {
            for (int j = i + 1; j + 1 < (int) num.size(); ++j) {
                int a = 0; // 第1个数：num[a, b]
                int b = i; // 第2个数：num[b + 1, c]
                int c = j; // 第3个数：num[c + 1, m]（m取决于(a+b)的位数）
                while (true) {
                    if ((b - a + 1 > 1 && num[a] == '0') || (c - b > 1 && num[b + 1] == '0')) {  // 跳过包含前导0的情况
                        break;
                    }
                    auto x = num.substr(a, b - a + 1);
                    auto y = num.substr(b + 1, c - b);
                    auto z = addNums(x, y);
                    if (num.substr(c + 1, z.size()) != z) {  // z != x + y
                        break;
                    }
                    a = b + 1;
                    b = c;
                    c += (int) z.size();
                    if (c + 1 >= num.size()) {  // 第3个数不存在，已到达结尾
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    string addNums(const string &a, const string &b) {  // 逆序遍历a、b，从个位开始处理
        string c;
        for (int i = 1, t = 0; i <= a.size() || i <= b.size() || t; ++i) {
            if (i <= a.size()) {
                t += a[a.size() - i] - '0';
            }
            if (i <= b.size()) {
                t += b[b.size() - i] - '0';
            }
            c.push_back((char) ('0' + t % 10));
            t /= 10;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0306_H
