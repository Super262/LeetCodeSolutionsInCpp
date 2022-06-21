//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0624_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0624_H

#include <vector>

using namespace std;

class Solution {
    // 我们需要在2个不同的数组中分别选择最大值max_val和最小值min_val，并得到答案abs(max_val-min_val)
    // 巧妙方法：初始时，min_val和max_val都来自arrays[0]；从arrays[1]开始遍历，更新答案，可保证min_val和max_val来自不同的数组
public:
    int maxDistance(const vector<vector<int>> &arrays) {
        int ans = 0;
        auto max_val = arrays[0].back();
        auto min_val = arrays[0][0];
        for (int i = 1; i < (int) arrays.size(); ++i) {
            ans = max(ans, abs(arrays[i][0] - max_val));
            ans = max(ans, abs(arrays[i].back() - min_val));
            max_val = max(max_val, arrays[i].back());
            min_val = min(min_val, arrays[i][0]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0624_H
