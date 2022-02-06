//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0168_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0168_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    string convertToTitle(int n) {  // 直接背诵
        string res;
        while (n) {
            n--;
            res += (char) (n % 26 + 'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0168_H
