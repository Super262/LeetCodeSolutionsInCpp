//
// Created by Fengwei Zhang on 2/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0696_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0696_H

#include <string>

using namespace std;

class Solution {
    // 直接背诵：若s由k个连续的1和k个连续的0组成，s共包含k个满足题意的子串
public:
    int countBinarySubstrings(const string &s) {
        int res = 0, last = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) j++;
            int cur = j - i;
            i = j - 1;
            res += min(last, cur);
            last = cur;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0696_H
