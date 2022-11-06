//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0125_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0125_H

#include <string>

using namespace std;

class Problem0125 {
public:
    bool isPalindrome(const string &s) {
        int l = 0;
        auto r = (int) s.size() - 1;
        while (l < r) {
            while (l < r && !checkCh(s[l])) {
                ++l;
            }
            while (l < r && !checkCh(s[r])) {
                --r;
            }
            if (l < r && tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

private:
    bool checkCh(const char &ch) {
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        return false;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0125_H
