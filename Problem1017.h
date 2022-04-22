//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1017_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1017_H

#include <string>

using namespace std;

class Solution {
    // 短除法：注意区分C++中取余运算和数学中取余运算的区别
    // 为了使余数为正数，我们可以将余数加上基数的绝对值保证其为正数，同时更新商为：(被除数-余数) / 除数
    // https://www.acwing.com/solution/content/9902/
public:
    string baseNeg2(int n) {
        if (!n) {
            return "0";
        }
        string ans;
        while (n) {
            auto r = ((n % (-2)) + 2) % 2;
            n = (n - r) / -2;
            ans += (char) ('0' + r);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1017_H
