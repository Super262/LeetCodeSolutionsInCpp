//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0686_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0686_H

#include <string>

using namespace std;

class Solution {
    // 经典算法，直接背诵：KMP
    // 设字符串s包含k+1个a，可推出b的匹配起点在第一段a，k是满足k*a.size()>b的最小值
public:
    int repeatedStringMatch(const string &a, const string &b) {
        string s = a;
        while (s.size() < b.size()) {
            s += a;
        }
        s += a;
        const auto m = (int) b.size();
        int fail[m];
        buildFail(b, fail);
        int i = 0, j = 0;
        while (i < (int) s.size()) {
            if (s[i] == b[j]) {
                ++i;
                ++j;
            } else if (j) {
                j = fail[j - 1];
            } else {
                ++i;
            }
            if (j == m) {
                return (int) ((i + (a.size() - 1)) / a.size());
            }
        }
        return -1;
    }

private:
    void buildFail(const string &s, int fail[]) {
        int l = 0;
        int r = 1;
        fail[l] = 0;
        while (r < (int) s.size()) {
            if (s[r] == s[l]) {
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0686_H
