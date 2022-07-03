//
// Created by Fengwei Zhang on 7/3/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0660_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0660_H

#include <string>

using namespace std;

class Solution {
    // 逆向思考，我们希望找到第n个不含"9"的数字，等价于找到第n个九进制数，因为不包含"9"的数字序列就是由九进制数字组成的序列
public:
    int newInteger(int n) {
        string ans;
        while (n) {
            ans += (char) ('0' + (n % 9));
            n /= 9;
        }
        reverse(ans.begin(), ans.end());
        return stoi(ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0660_H
