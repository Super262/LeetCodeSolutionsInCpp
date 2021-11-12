//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0168_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0168_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int k = 1;  // 结果长度
        for (long long p = 26; (long long) n > p; p *= 26) {
            n -= (int) p;
            ++k;
        }
        n--;
        string res;
        while (k--) {
            res += (char) ('A' + n % 26);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0168_H
