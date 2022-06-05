//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0455_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0455_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 当s[i] >= g[i]时，两者可以匹配，原问题转化为二分图最大匹配问题
    // 贪心算法：优先分配较小的饼干到当前孩子
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for (int i = 0, j = 0; i < (int) g.size() && j < (int) s.size(); ++j) {
            if (g[i] <= s[j]) {
                ++i;
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0455_H
