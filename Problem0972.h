//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0972_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0972_H

#include <string>

using namespace std;

class Solution {
    // 数学知识："0.(52)"（循环节）等于52/99
public:
    bool isRationalEqual(const string &s, const string &t) {
        return getFraction(s) == getFraction(t);
    }

private:
    static pair<long long, long long> getFraction(const string &s) {  // 返回 (分子,分母)
        int i = 0;
        // 获取整数部分
        long long a = 0;
        while (i < s.size() && s[i] != '.') {
            a = a * 10 + (s[i] - '0');
            ++i;
        }
        pair<long long, long long> ans(a, 1);
        ++i;  // 跳过"."

        // 获取小数部分为分数（循环节以前）
        a = 0;
        long long b = 1;
        while (i < s.size() && s[i] != '(') {
            a = a * 10 + (s[i] - '0');
            b *= 10;
            ++i;
        }
        ans = add(ans, {a, b});
        ++i;  // 跳过"("

        // 获取循环节部分为分数
        auto t = b;  // 保存循环节相对于"."的偏移量
        a = 0;
        b = 0;
        while (i < s.size() && s[i] != ')') {
            a = a * 10 + (s[i] - '0');
            b = b * 10 + 9;
            ++i;
        }
        ans = add(ans, {a, b * t});
        return ans;
    }

    static pair<long long, long long> add(const pair<long long, long long> &a, const pair<long long, long long> &b) {
        if (!b.second) {
            return a;
        }
        if (!a.second) {
            return b;
        }
        pair<long long, long long> ans(a.first * b.second + b.first * a.second, a.second * b.second);
        auto d = gcd(ans.first, ans.second);
        ans.first /= d;
        ans.second /= d;
        return ans;
    }

    static long long gcd(long long a, long long b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0972_H
