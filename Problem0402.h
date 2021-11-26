//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0402_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0402_H

#include <string>

using namespace std;

class Solution {
    // 贪心算法：背诵代码！
public:
    string removeKdigits(const string &num, int k) {
        k = min((int) num.size(), k);
        string res;
        for (const auto &ch: num) {
            while (!res.empty() && k > 0 && res.back() > ch) {
                res.pop_back();
                --k;
            }
            res.push_back(ch);
        }
        while (k > 0) {  // 还有待删除的字符
            res.pop_back();
            --k;
        }
        k = 0;  // 计算前导零个数
        for (const auto &ch: res) {
            if (ch != '0') {
                break;
            }
            ++k;
        }
        if (k == res.size()) {  // 全是"0"，直接返回"0"
            return "0";
        }
        return res.substr(k);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0402_H
