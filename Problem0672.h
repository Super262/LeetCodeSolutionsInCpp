//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0672_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0672_H

#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，直接背诵
    // https://leetcode-cn.com/problems/bulb-switcher-ii/solution/deng-pao-kai-guan-ii-by-leetcode/
public:
    int flipLights(int n, const int m) {
        n = min(n, 3);
        if (m == 0) {
            return 1;
        }
        if (m == 1) {
            int s[3] = {2, 3, 4};
            return s[n - 1];
        }
        if (m == 2) {
            int s[3] = {2, 4, 7};
            return s[n - 1];
        }
        int s[3] = {2, 4, 8};
        return s[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0672_H
