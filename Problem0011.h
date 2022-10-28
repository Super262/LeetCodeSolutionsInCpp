//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0011_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0011_H

#include <vector>

using namespace std;

class Problem0011 {
    // 直接背诵，双指针算法经典题目
public:
    int maxArea(const vector<int> &height) {
        int ans = 0;
        int l = 0;
        auto r = (int) height.size() - 1;
        while (l < r) {
            auto y = min(height[l], height[r]);
            ans = max(ans, (r - l) * y);
            if (height[l] == y) {  // 左边的是目标高度，跳过左边
                ++l;
            } else {  // 右边的是目标高度，跳过右边
                --r;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0011_H
