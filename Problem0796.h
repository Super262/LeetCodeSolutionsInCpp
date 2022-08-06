//
// Created by Fengwei Zhang on 3/30/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0796_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0796_H

#include <string>

using namespace std;

class Problem0796 {
    // 前缀哈希加速字符串比较；设字符串长度为n，若b是由a翻转得到，那么存在i使得a[0:i]==b[n-i-1,n-1]
public:
    bool rotateString(const string &a, const string &b) {
        if (a == b) {
            return true;
        }
        if (a.size() != b.size()) {
            return false;
        }
        auto s = a + b;
        const auto n = (int) s.size();
        unsigned long long h[n + 1];
        unsigned long long p[n + 1];
        p[0] = 1;
        h[0] = 0;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }
        for (int k = 1; k < a.size(); ++k) {
            if (getHash(1, k, h, p) == getHash(n - k + 1, n, h, p) &&
                getHash(k + 1, (int) a.size(), h, p) == getHash((int) a.size() + 1, n - k, h, p)) {
                return true;
            }
        }
        return false;
    }

private:
    const int P = 131;

    unsigned long long getHash(int l, int r, unsigned long long h[], const unsigned long long p[]) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0796_H
