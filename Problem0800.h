//
// Created by Fengwei Zhang on 8/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0800_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0800_H

#include <string>

using namespace std;

class Problem0800 {
    // 根据题意可知，我们要将color的相邻2位AB替换为00~ff中某2位XX，使得(AB-XX)绝对值最小
    // 由于00～ff都是17的倍数，17/2=8；若AB%17>8，替换AB为更大的数字；若AB%17<8，替换AB为较小的数字
public:
    string similarRGB(const string &color) {
        string ans = "#";
        for (int i = 1; i < (int) color.size(); i += 2) {
            auto x = hexToDec(color[i], color[i + 1]);
            if (x % 17 > 8) {
                ans += decToHex(x / 17 + 1, x / 17 + 1);
            } else {
                ans += decToHex(x / 17, x / 17);
            }
        }
        return ans;
    }

private:
    int hexToDec(char a, char b) {  // 将16进制数字"ab"转换为10进制数x
        int x = 0;
        if ('0' <= a && a <= '9') {
            x += (a - '0') * 16;
        } else {
            x += ((a - 'a') + 10) * 16;
        }
        if ('0' <= b && b <= '9') {
            x += b - '0';
        } else {
            x += (b - 'a') + 10;
        }
        return x;
    }

    string decToHex(int a, int b) {  // 将10进制数字"a*16+b"转换为16进制数x
        string x;
        if (a < 10) {
            x += (char) ('0' + a);
        } else {
            x += (char) ('a' + (a - 10));
        }
        if (b < 10) {
            x += (char) ('0' + b);
        } else {
            x += (char) ('a' + (b - 10));
        }
        return x;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0800_H
