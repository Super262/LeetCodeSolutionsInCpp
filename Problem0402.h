//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0402_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0402_H

#include <string>

using namespace std;

class Solution {
    // 贪心算法：优先保存靠前的、较小的字符
public:
    string removeKdigits(const string &num, int k) {
        k = min((int) num.size(), k);
        string ans;
        ans.reserve(num.size() - k);
        for (const auto &ch: num) {
            while (!ans.empty() && k > 0 && ans.back() > ch) {
                ans.pop_back();
                --k;
            }
            ans += ch;
        }
        while (k > 0) {  // 还有待删除的字符
            ans.pop_back();
            --k;
        }
        k = 0;  // 计算前导零个数
        for (const auto &ch: ans) {
            if (ch != '0') {
                break;
            }
            ++k;
        }
        if (k == ans.size()) {  // 全是"0"，直接返回"0"
            return "0";
        }
        return ans.substr(k);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0402_H
