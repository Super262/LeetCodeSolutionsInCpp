//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0264_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0264_H

class Solution {
public:
    int nthUglyNumber(int n) {
        // 多路归并：https://www.acwing.com/solution/content/20166/
        vector<int> result(1, 1);  // 初始时只包括1
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        while (result.size() < n) { // 注意：构造新丑数时，只能基于已有的丑数
            auto r1 = 2 * result[p1];
            auto r2 = 3 * result[p2];
            auto r3 = 5 * result[p3];
            auto minimal = min(r1, min(r2, r3));
            result.emplace_back(minimal);
            if (minimal == r1) {
                ++p1;
            }
            if (minimal == r2) {
                ++p2;
            }
            if (minimal == r3) {
                ++p3;
            }
        }
        return result[n - 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0264_H
