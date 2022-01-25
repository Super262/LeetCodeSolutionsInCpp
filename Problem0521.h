//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0521_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0521_H

#include <string>

using namespace std;

class Solution {
    // 脑筋急转弯，直接背诵
public:
    int findLUSlength(const string &a, const string &b) {
        if (a == b) {
            return -1;
        }
        return (int) max(a.size(), b.size());
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0521_H
