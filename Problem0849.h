//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0849_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0849_H

#include <vector>

using namespace std;

class Solution {
    // 双指针算法，从左向右检查每个区间[i:j]，i是左边第一个空位，j是第一个人
public:
    int maxDistToClosest(const vector<int> &seats) {
        int ans = 0;
        for (int i = 0; i < (int) seats.size(); ++i) {
            if (seats[i]) {
                continue;
            }
            auto j = i + 1;
            while (j < (int) seats.size() && !seats[j]) {
                ++j;
            }
            if (!i || j == (int) seats.size()) {
                ans = max(ans, j - i);
            } else {
                ans = max(ans, (j - i + 1) / 2);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0849_H
