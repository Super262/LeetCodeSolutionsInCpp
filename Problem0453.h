//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0453_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0453_H

#include <vector>

using namespace std;

class Solution {
    // 为n-1个元素加1，等价于给1个元素减1；因此，我们找到最小值minv，求其它元素和它的距离
public:
    int minMoves(const vector<int> &nums) {
        int ans = 0;
        int minv = INT_MAX;
        for (const auto &x: nums) {
            minv = min(minv, x);
        }
        for (const auto &x: nums) {
            ans += x - minv;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0453_H
