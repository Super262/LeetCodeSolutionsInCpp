//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0264_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0264_H

#include <vector>

using namespace std;

class Solution {
    // 类似多路归并：每次选择一个最小值；第2个丑数的候选集是{2}，{3}，{5}，当某个数x被加入结果集，就在源候选集加入一个新数字
    // https://www.acwing.com/solution/content/20166/
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1, 1);  // 初始时只包括1
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        ans.reserve(n);
        while ((int) ans.size() < n) { // 注意：构造新丑数时，只能基于已有的丑数
            auto r1 = 2 * ans[p1];
            auto r2 = 3 * ans[p2];
            auto r3 = 5 * ans[p3];
            auto minimal = min(r1, min(r2, r3));
            ans.emplace_back(minimal);
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
        return ans.back();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0264_H
