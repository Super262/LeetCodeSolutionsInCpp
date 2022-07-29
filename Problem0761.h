
//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0761_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0761_H

#include <vector>
#include <string>

using namespace std;

class Problem0761 {
    // 贪心算法 + 递归处理；首先，我们观察到，特殊二进制字符串的首位是1、末位是0；对于输入s，存在2种情况：
    // (1) s能够拆分为多个特殊二进制字符串，去掉首尾的1、0后得到的不是特殊二进制字符串
    // (2) s只由1个特殊二进制字符串构成，去掉首尾的1、0后得到的也是特殊二进制字符串
    // 因此，若发现s[l:r]是特殊二进制字符串，我们递归处理s[l+1,r-1]，将结果存入序列；最后从大到小排序序列，拼接成答案
    // https://www.acwing.com/solution/content/3594/
public:
    string makeLargestSpecial(const string &s) {
        if (s.empty()) {
            return "";
        }
        const auto &n = (int) s.size();
        vector<string> parts;
        for (int l = 0, r = 0, cnt = 0; r < n; ++r) {
            if (s[r] == '1') {
                ++cnt;
            } else {
                --cnt;
            }
            if (!cnt) {
                parts.emplace_back("1" + makeLargestSpecial(s.substr(l + 1, r - l - 1)) + "0");
                l = r + 1;
            }
        }
        sort(parts.rbegin(), parts.rend());
        string ans;
        for (const auto &p: parts) {
            ans += p;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0761_H
