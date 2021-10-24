//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0028_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0028_H

#include <string>
#include <vector>

using namespace std;

class Problem0028 {
public:
    int strStr(const string &haystack, const string &needle) {
        if (needle.empty()) {
            return 0;
        }
        auto nextStart = buildNextStart(needle);
        int hi = 0, ni = 0;
        while (hi < (int) haystack.size()) {
            if (haystack[hi] == needle[ni]) {
                ++hi;
                ++ni;
            } else if (ni) {
                ni = nextStart[ni - 1];
            } else {
                ++hi;
            }
            if (ni == (int) needle.size()) {
                return hi - ni;
            }
        }
        return -1;
    }

    vector<int> buildNextStart(const string &needle) {
        vector<int> nextStart(needle.size(), 0);
        nextStart[0] = 0;
        int left = 0, right = 1;
        while (right < (int) needle.size()) {
            if (needle[left] == needle[right]) {
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
        return nextStart;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0028_H
