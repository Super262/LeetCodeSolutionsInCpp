//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0214_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0214_H

#include <string>

using namespace std;

class Solution {
    // 加强对KMP算法的理解，背诵代码！
    // https://www.acwing.com/solution/content/19819/
public:
    string shortestPalindrome(const string &s) {
        const string temp = s + "#" + string(s.rbegin(), s.rend());
        const auto m = (int) temp.size();
        int fail[m];
        buildFail(temp, fail);
        auto left = s.substr(0, fail[m - 1]);
        auto right = s.substr(fail[m - 1]);
        return string(right.rbegin(), right.rend()) + left + right;
    }

private:
    void buildFail(const string &s, int fail[]) {
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < (int) s.size()) {
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
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0214_H
