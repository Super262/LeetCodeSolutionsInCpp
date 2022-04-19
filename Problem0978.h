//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0978_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0978_H

#include <vector>

using namespace std;

class Solution {
    // 动态规划：f[i][0]表示以a[i]结尾的上升段子数组长度，f[i][1]表示以a[i]结尾的下降段子数组
public:
    int maxTurbulenceSize(const vector<int> &arr) {
        int ans = 1;
        for (int i = 1, f0 = 1, f1 = 1; i < (int) arr.size(); ++i) {
            if (arr[i - 1] > arr[i]) {
                f1 = f0 + 1;
                f0 = 1;
            } else if (arr[i - 1] < arr[i]) {
                f0 = f1 + 1;
                f1 = 1;
            } else {
                f0 = 1;
                f1 = 1;
            }
            ans = max(ans, max(f1, f0));
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0978_H
