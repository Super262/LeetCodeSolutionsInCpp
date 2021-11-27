//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0405_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0405_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(unsigned int num) {
        if (num == 0) {
            return "0";
        }
        string res;
        const string dict = "0123456789abcdef";
        while (num) {
            res.push_back(dict[num & 0xf]);
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0405_H
