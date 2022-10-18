//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1012_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1012_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1012 {
    // 数位DP模版题：求补集，统计所有数位都不重复的正整数的个数ans，答案为n-ans-1
public:
    int numDupDigitsAtMostN(int n) {
        auto digits = getDigits(n);
        int ans = 0;
        // 计算所有长度小于n的、各位不重复的数字的个数
        for (int length = 1; length < (int) digits.size(); ++length) {
            ans += 9 * perm(9, length - 1);  // 9 * C(9, len-1)：最高位只有9种选择，没有前导零
        }
        bool used[10];  // digits[n-1:i+1]使用了哪些数字
        memset(used, 0, sizeof used);
        for (auto i = (int) digits.size() - 1; i >= 0; --i) {  // 计算所有长度等于n的、各位不重复的数字的个数
            int uni_cnt = 0;  // 当前位的可选数字
            for (int j = 0; j < digits[i]; ++j) {  // 确定[0:x)间可用的数字有多少
                if (used[j]) {
                    continue;
                }
                ++uni_cnt;
            }
            if (i == (int) digits.size() - 1 && !used[0]) {  // 最高位不能有前导零
                --uni_cnt;
            }
            if (uni_cnt > 0) {
                ans += uni_cnt * perm(10 - ((int) digits.size() - i), i);  // 第[0:i-1]可选的数字有(10 - (n-i))个
            }
            if (used[digits[i]]) {  // x在前面已经出现，当前位不能为x，停止探索
                return n - ans;
            }
            used[digits[i]] = true;
        }
        return n - ans - 1;
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

    static int perm(int a, int b) {
        int ans = 1;
        for (int i = a, j = 0; j < b; --i, ++j) {
            ans *= i;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1012_H
