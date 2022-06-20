//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0564_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0564_H

#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
    // 设n的长度为l，n的前半段为m，枚举时，我们只考虑前半段m即可。
    // 脑筋急转弯，结果产生在5个数中：10^(l-1)-1，(m-1)(m-1)，mm，(m+1)(m+1)，10^l+1；我们枚举这5个数，找到答案
    // https://www.acwing.com/solution/content/96053/
public:
    string nearestPalindromic(const string &n) {
        const auto length = (int) n.size();
        unordered_set<long long> candidates;
        candidates.insert((long long) pow(10, length - 1) - 1);
        candidates.insert((long long) pow(10, length) + 1);
        auto m = stoll(n.substr(0, (length + 1) / 2));
        for (auto i = m - 1; i <= m + 1; ++i) {
            auto a = to_string(i);
            auto b = string(a.rbegin(), a.rend());
            if (length % 2) {
                candidates.insert(stoll(a + b.substr(1)));
            } else {
                candidates.insert(stoll(a + b));
            }
        }
        auto k = stoll(n);
        candidates.erase(k);
        long long ans = INT64_MAX;
        for (const auto &x: candidates) {
            auto a = abs(ans - k);
            auto b = abs(x - k);
            if (a < b || (a == b && x >= ans)) {
                continue;
            }
            ans = x;
        }
        return to_string(ans);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0564_H
