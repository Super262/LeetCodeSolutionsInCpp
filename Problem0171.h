//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0171_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0171_H

#include <string>

using namespace std;

class Solution {
    // 结合168题，直接背诵！
public:
    int titleToNumber(const string &title) {
        int res = 0;
        for (const char &ch: title) {
            res = res * 26 + (ch - 'A' + 1);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0171_H
