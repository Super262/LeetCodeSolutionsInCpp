//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0455_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0455_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 匈牙利算法：当s[i] >= g[i]时，两者可以匹配，原问题转化为二分图最大匹配问题
    // 贪心算法，直接背诵：https://www.acwing.com/solution/content/23803/
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int result = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                ++i;
                ++result;
            }
            ++j;
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0455_H
