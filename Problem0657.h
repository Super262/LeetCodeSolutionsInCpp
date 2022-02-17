//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0657_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0657_H

#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(const string &moves) {
        int x = 0, y = 0;
        for (const auto &ch: moves) {
            if (ch == 'U') {
                ++x;
            } else if (ch == 'D') {
                --x;
            } else if (ch == 'L') {
                --y;
            } else {
                ++y;
            }
        }
        return !x && !y;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0657_H
