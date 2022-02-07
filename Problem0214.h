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
        int next_start[m];
        buildNext(temp, next_start);
        auto left = s.substr(0, next_start[m - 1]);
        auto right = s.substr(next_start[m - 1]);
        return string(right.rbegin(), right.rend()) + left + right;
    }

private:
    void buildNext(const string &s, int next_start[]) {
        int l = 0;
        int r = 1;
        next_start[l] = 0;
        while (r < (int) s.size()) {
            if (s[l] == s[r]) {
                ++l;
                next_start[r] = l;
                ++r;
            } else if (l) {
                l = next_start[l - 1];
            } else {
                next_start[r] = 0;
                ++r;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0214_H
