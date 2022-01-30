//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0598_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0598_H

#include <vector>

using namespace std;

class Solution {
    // 直接背诵，转化思路：求所有操作交集的面积（备注）
public:
    int maxCount(int m, int n, const vector<vector<int>> &ops) {
        int x = m;
        int y = n;
        for (const auto &op: ops) {
            x = min(x, op[0]);
            y = min(y, op[1]);
        }
        return x * y;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0598_H
