//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0551_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0551_H

#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(const string &s) {
        int l = 0, a = 0;
        for (const auto &ch: s) {
            if (ch == 'A') {
                ++a;
                l = 0;
            } else if (ch == 'L') {
                ++l;
            } else {
                l = 0;
            }
            if (a >= 2 || l >= 3) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0551_H
