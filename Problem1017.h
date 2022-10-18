//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1017_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1017_H

#include <string>

using namespace std;

class Problem1017 {
    // 如果n=0，直接返回"0"；若n!=0，重复执行如下操作，直到n=0：
    //    (1) 计算n的绝对值除以-2的余数，确保余数是0或1，将余数拼接到字符串的末尾
    //    (2) 将n的值减去余数，然后将n的值除以−2
    // 上述操作结束之后，字符串为负二进制数反转之后的结果，将字符串翻转之后得到负二进制数
public:
    string baseNeg2(int n) {
        if (!n) {
            return "0";
        }
        string ans;
        while (n) {
            auto r = abs(n) % (-2);
            ans += (char) ('0' + r);
            n -= r;
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1017_H
