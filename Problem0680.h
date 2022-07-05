//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0680_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0680_H

#include <string>

using namespace std;

class Solution {
    // 双指针，l从左向右移动、r从右向左移动；若遇到s[l]!=s[r]，分别尝试跳过l、跳过r，检查剩余部分
public:
    bool validPalindrome(const string &s) {
        int l = 0;
        auto r = (int) s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                if (check(s, l + 1, r) || check(s, l, r - 1)) {
                    return true;
                }
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

private:
    bool check(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0680_H
