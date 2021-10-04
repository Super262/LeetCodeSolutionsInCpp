//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1347_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1347_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

class Problem1347 {
private:
    int minSteps(string s, string t) {
        const int n = (int) s.size();
        int chCntS[26];
        int chCntT[26];
        memset(chCntS, 0, sizeof chCntS);
        memset(chCntT, 0, sizeof chCntT);
        for (int i = 0; i < n; ++i) {
            ++chCntS[s[i] - 'a'];
            ++chCntT[t[i] - 'a'];
        }
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if (chCntS[i] >= chCntT[i]) {
                continue;
            }
            result += chCntT[i] - chCntS[i];
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1347_H
