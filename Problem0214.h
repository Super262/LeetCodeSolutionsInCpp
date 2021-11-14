//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0214_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0214_H

#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(const string &s) {
        // 加强对KMP算法的理解
        // 背诵代码！
        // https://www.acwing.com/solution/content/19819/
        const int n = (int) s.size();
        const string temp = s + "#" + string(s.rbegin(), s.rend());
        const int m = (int) temp.size();
        int nextStart[m];
        buildNextStart(temp, nextStart);
        auto leftPart = s.substr(0, nextStart[m - 1]);
        auto rightPart = s.substr(nextStart[m - 1]);
        return string(rightPart.rbegin(), rightPart.rend()) + leftPart + rightPart;
    }

private:
    void buildNextStart(const string &s, int nextStart[]) {
        const int n = (int) s.size();
        int left = 0;
        int right = 1;
        nextStart[0] = 0;
        while (right < n) {
            if (s[left] == s[right]) {
                ++left;
                nextStart[right] = left;
                ++right;
            } else if (left) {
                left = nextStart[left - 1];
            } else {
                nextStart[right] = 0;
                ++right;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0214_H
