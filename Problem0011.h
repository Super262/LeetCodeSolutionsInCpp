//
// Created by Fengwei Zhang on 9/29/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0011_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0011_H

#include <vector>

using namespace std;

class Problem0011 {
private:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0;
        int r = (int) height.size() - 1;
        while (l < r) {
            result = max(result, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0011_H
