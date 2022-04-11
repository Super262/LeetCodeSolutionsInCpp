//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0906_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0906_H

#include <string>

using namespace std;

class Solution {
    // x = sqrt(left/right)至多有9位，由于x是回文数，我们可以尝试枚举x的左半部（1～20001）
public:
    int superpalindromesInRange(const string &left, const string &right) {
        int ans = 0;
        const auto l = stoull(left);
        const auto r = stoull(right);
        for (int i = 1; i < 20002; ++i) {
            auto a = to_string(i);
            auto b = string(a.rbegin(), a.rend());
            // 注意：拼接时有2种选择
            if (isPalindrome(a + b, l, r)) {
                ++ans;
            }
            if (isPalindrome(a + b.substr(1), l, r)) {
                ++ans;
            }
        }
        return ans;
    }

private:
    static bool isPalindrome(const string &s, unsigned long l, unsigned long long r) {
        auto x = stoull(s);
        if (x > INT_MAX) {
            return false;
        }
        x *= x;
        if (x < l || x > r) {
            return false;
        }
        auto xs = to_string(x);
        for (int i = 0, j = (int) xs.size() - 1; i < j; ++i, --j) {
            if (xs[i] != xs[j]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0906_H
