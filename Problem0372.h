//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0372_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0372_H

#include <vector>

using namespace std;

class Solution {
    // 转化为多个子问题：a ^ (12345) % p == a ^ (1234) ^ 10 * a ^ (5) % p
public:
    int superPow(const int &a, const vector<int> &b) {
        const int mod = 1337;
        const int idx = (int) b.size() - 1;
        return dfs(a, b, idx, mod);
    }

private:
    int dfs(const int &a, const vector<int> &b, const int &idx, const int &mod) {  // 求解 a^(b[0:idx])
        if (idx == 0) {
            return (int) qmi(a, b[idx], mod);
        }
        // a ^ (12345) % p == a ^ (1234) ^ 10 * a ^ (5) % p
        return (int) (qmi(dfs(a, b, idx - 1, mod), 10, mod) * qmi(a, b[idx], mod) % mod);
    }

    static long long qmi(long long a, long long p, const long long &mod) {
        long long result = 1;
        while (p) {
            if (p & 1) {
                result = result * a % mod;
            }
            a = a * a % mod;
            p >>= 1;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0372_H
