//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0246_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0246_H

#include <string>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(const string &num) {
        int l = 0;
        int r = (int) num.size() - 1;
        while (l <= r) {
            if (num[l] == '2' || num[l] == '3' || num[l] == '4' || num[l] == '5' || num[l] == '7') {
                return false;
            }
            if (num[r] == '2' || num[r] == '3' || num[r] == '4' || num[r] == '5' || num[r] == '7') {
                return false;
            }
            if (num[l] == '0') {
                if (num[r] != '0') {
                    return false;
                }
            } else if (num[l] == '1') {
                if (num[r] != '1') {
                    return false;
                }
            } else if (num[l] == '6') {
                if (num[r] != '9') {
                    return false;
                }
            } else if (num[l] == '8') {
                if (num[r] != '8') {
                    return false;
                }
            } else {
                if (num[r] != '6') {
                    return false;
                }
            }
            ++l;
            --r;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0246_H
