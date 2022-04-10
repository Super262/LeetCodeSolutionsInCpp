//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0902_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0902_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 数位DP：保存高位的信息，探索低位
public:
    int atMostNGivenDigitSet(vector<string> &chs, int n) {
        int ans = 0;
        int prev = 0;  // 当前已经被构造出的高位数字
        auto digits = getDigits(n);  // 获得n的每位
        auto power = initPower((int) chs.size(), (int) digits.size());  // power[x] = len(chs)^x
        for (auto i = (int) digits.size() - 1; i >= 0; --i) {  // 统计满足题意的、长度为len(n)的数
            bool has_equal = false;
            for (const auto &ch: chs) {  // 寻找小于digits[i]的数字
                auto x = ch[0] - '0';
                if (x >= digits[i]) {
                    has_equal = digits[i] == x;
                    break;
                }
                ans += power[i];
            }
            if (!has_equal) {  // 未找到和digits[i]相等的数字，无法继续构造高位
                break;
            }
            prev = prev * 10 + digits[i];  // 更新高位部分
            if (!i && prev == n) {  // 可以构造等于n的数
                ++ans;
            }
        }
        for (int i = 1; i < (int) digits.size(); ++i) {  // 统计位数小于len(n)的数
            ans += power[i];
        }
        return ans;
    }

private:
    static vector<int> getDigits(int x) {
        vector<int> ans;
        while (x) {
            ans.emplace_back(x % 10);
            x /= 10;
        }
        return ans;
    }

    static vector<int> initPower(int a, int k) {
        vector<int> ans(k + 1);
        ans[0] = 1;
        for (int i = 1; i <= k; ++i) {
            ans[i] = ans[i - 1] * a;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0902_H
