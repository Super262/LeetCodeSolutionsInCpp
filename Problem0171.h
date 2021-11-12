//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0171_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0171_H

#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(const string &title) {  // 结合168题，直接背诵！
        const int n = (int) title.size();
        int result = 0;
        long long p = 26;
        for (int i = 0; i < n - 1; ++i) {
            result += (int) p;
            p *= 26;
        }
        int t = 0;
        for (const auto &ch: title) {
            t *= 26;
            t += ch - 'A';
        }
        ++t;
        result += t;
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0171_H
