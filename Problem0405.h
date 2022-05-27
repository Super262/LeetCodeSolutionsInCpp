//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0405_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0405_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 将数字和"0xf"做"&"运算，获得最低位（16进制），再右移4位，继续操作
public:
    string toHex(unsigned int num) {
        if (num == 0) {
            return "0";
        }
        string ans;
        const string dict = "0123456789abcdef";
        while (num) {
            ans += dict[num & 0xf];
            num >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0405_H
