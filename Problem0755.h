//
// Created by Fengwei Zhang on 7/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0755_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0755_H

#include <vector>

using namespace std;

class Problem0755 {
    // 直接模拟；当水落在位置k时，我们首先检查它是否可以向左流动而下降；若未在左侧发现可行位置，尝试检查右侧
    // 检查可能位置best时，若当前位置比best更高，退出检查；否则，继续检查，更新best为较低位置
public:
    vector<int> pourWater(vector<int> &heights, int volume, int k) {
        for (int x = 0; x < volume; ++x) {
            auto best = k;
            for (int i = k - 1; i >= 0; --i) {
                if (heights[i] > heights[best]) {
                    break;
                }
                if (heights[i] < heights[best]) {
                    best = i;
                }
            }
            if (best == k) {
                for (int i = k + 1; i < (int) heights.size(); ++i) {
                    if (heights[i] > heights[best]) {
                        break;
                    }
                    if (heights[i] < heights[best]) {
                        best = i;
                    }
                }
            }
            ++heights[best];
        }
        return heights;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0755_H
