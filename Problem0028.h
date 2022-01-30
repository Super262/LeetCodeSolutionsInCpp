//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0028_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0028_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // KMP算法，直接背诵
public:
    int strStr(const string &haystack, const string &needle) {
        if (needle.empty()) {
            return 0;
        }
        auto next_start = buildNextStart(needle);
        int hi = 0, ni = 0;
        while (hi < (int) haystack.size()) {
            if (haystack[hi] == needle[ni]) {
                ++hi;
                ++ni;
            } else if (ni) {
                ni = next_start[ni - 1];
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
    vector<int> buildNextStart(const string &p) {
        vector<int> next_start(p.size(), 0);
        next_start[0] = 0;
        int left = 0, right = 1;
        while (right < (int) p.size()) {
            if (p[left] == p[right]) {
                ++left;
                next_start[right] = left;
                ++right;
            } else if (left) {
                left = next_start[left - 1];
            } else {
                next_start[right] = 0;
                ++right;
            }
        }
        return next_start;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0028_H
