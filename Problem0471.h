//
// Created by Fengwei Zhang on 6/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0471_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0471_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 区间DP，思路新奇：f[i][j]表示将s[i:j]编码的最短字符串；f[i][j]=min{f[i][k]+f[k+1][j],i<=k<j}；从1开始枚举区间长度、分界点
    // 若字符串长度小于5，我们直接返回原串；若要获得最短编码，我们要求得s的周期，借用LeetCode 459的算法
    // 细节："s.find_first_of(a,0)"从s的索引0检验a的第0个字符，不会检验整个字符串
public:
    string encode(const string &s) {
        const auto n = (int) s.size();
        string f[n][n];
        for (int length = 1; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                auto j = i + length - 1;
                auto t = s.substr(i, length);
                f[i][j] = t;
                if (length <= 4) {
                    continue;
                }
                auto p = repeatedPattern(t);
                if (p != -1) {
                    f[i][j] = to_string(length / p) + '[' + f[i][i + p - 1] + ']';
                }
                for (auto k = i; k < j; ++k) {
                    if (f[i][j].size() > f[i][k].size() + f[k + 1][j].size()) {
                        f[i][j] = f[i][k] + f[k + 1][j];
                    }
                }
            }
        }
        return f[0][n - 1];
    }

private:
    int repeatedPattern(const string &s) {
        const auto n = (int) s.size();
        int fail[n];
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < n) {
            if (s[l] == s[r]) {
                ++l;
                fail[r] = l;
                ++r;
            } else if (l) {
                l = fail[l - 1];
            } else {
                fail[r] = 0;
                ++r;
            }
        }
        auto p = (n - 1) - fail[n - 1] + 1;
        if (p >= n || n % p) {
            return -1;
        }
        return p;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0471_H
