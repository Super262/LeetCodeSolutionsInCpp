//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0718_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0718_H

#include <vector>
#include <unordered_set>

using namespace std;

class Problem0718 {
    // 最长公共子序列：DP；最长公共子数组：二分 + 字符串哈希
    // 首先，我们计算出a[0:i]的哈希值ha[i+1]、b[0:i]的哈希值hb[i+1]；二分查找，设答案为l，我们枚举a、b中所有长度为l的子数组
    // 若存在a[i+i+l-1]=b[j:j+l-1]，证明l可行，我们尝试增大l；否则，我们减少l；使用哈希值（具有前缀和性质）判断a[i+i+l-1]=b[j:j+l-1]
public:
    int findLength(const vector<int> &a, const vector<int> &b) {
        const auto m = (int) a.size();
        const auto n = (int) b.size();
        unsigned long long power[max(n, m) + 1];
        unsigned long long ha[m + 1];
        unsigned long long hb[n + 1];
        init(m, a, n, b, power, ha, hb);
        int l = 0;
        auto r = min(m, n);
        while (l < r) {  // 二分公共数组的长度
            auto mid = l + (r - l + 1) / 2;
            if (hasSubarray(mid, m, n, power, ha, hb)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

private:
    const int P = 131;

    bool hasSubarray(const int l,
                     const int m,
                     const int n,
                     const unsigned long long power[],
                     const unsigned long long ha[],
                     const unsigned long long hb[]) {
        unordered_set<unsigned long long> arrays;
        for (int st = 1; st + l - 1 <= n; ++st) {
            auto ed = st + l - 1;
            auto t = hb[ed] - hb[st - 1] * power[ed - st + 1];
            arrays.insert(t);
        }
        for (int st = 1; st + l - 1 <= m; ++st) {
            auto ed = st + l - 1;
            auto t = ha[ed] - ha[st - 1] * power[ed - st + 1];
            if (arrays.count(t)) {
                return true;
            }
        }
        return false;
    }

    void init(const int m,
              const vector<int> &a,
              const int n,
              const vector<int> &b,
              unsigned long long power[],
              unsigned long long ha[],
              unsigned long long hb[]) const {  // 计算a、b的哈希和P的幂
        power[0] = 1;
        for (int i = 1; i <= max(n, m); ++i) {
            power[i] = power[i - 1] * P;
        }
        ha[0] = 0;
        for (int i = 1; i <= m; ++i) {
            ha[i] = ha[i - 1] * P + a[i - 1];
        }
        hb[0] = 0;
        for (int i = 1; i <= n; ++i) {
            hb[i] = hb[i - 1] * P + b[i - 1];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0718_H
