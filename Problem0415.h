//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0415_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0415_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // 大整数加法，从低位到高位，逐个求和、进位
public:
    string addStrings(const string &num1, const string &num2) {
        auto i = num1.rbegin();
        auto j = num2.rbegin();
        auto t = 0;
        string ans;
        ans.reserve(max(num1.size(), num2.size()) + 1);
        while (i != num1.rend() || j != num2.rend() || t) {
            if (i != num1.rend()) {
                t += *i - '0';
                i++;
            }
            if (j != num2.rend()) {
                t += *j - '0';
                j++;
            }
            ans += (char) (t % 10 + '0');
            t /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0415_H
