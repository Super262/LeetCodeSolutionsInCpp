//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0028_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0028_H

#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Problem0028 {
    // KMP算法，直接背诵
public:
    int strStr(const string &haystack, const string &needle) {
        if (needle.empty()) {
            return 0;
        }
        int fail[needle.size()];
        memset(fail, 0, sizeof fail);
        buildFail(needle, fail);
        int hi = 0, ni = 0;
        while (hi < (int) haystack.size()) {
            if (haystack[hi] == needle[ni]) {
                ++hi;
                ++ni;
            } else if (ni) {
                ni = fail[ni - 1];
            } else {
                ++hi;
            }
            if (ni == (int) needle.size()) {
                return hi - ni;
            }
        }
        return -1;
    }

private:
    void buildFail(const string &p, int fail[]) {
        int l = 0, r = 1;
        fail[l] = 0;
        while (r < (int) p.size()) {
            if (p[l] == p[r]) {
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

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0028_H
